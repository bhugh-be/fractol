/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:19:55 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/28 14:04:19 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_SRC_SIZE 100000

void			get_source(t_values *values)
{
	values->cl.source_str = (char *)malloc(MAX_SRC_SIZE);
	values->cl.source_size =
		read(values->fd, values->cl.source_str, MAX_SRC_SIZE);
	close(values->fd);
}

void			opencl_init(t_values *values)
{
	get_source(values);
	clGetPlatformIDs(1, &values->cl.platform_id, &values->cl.ret_num_platforms);
	clGetDeviceIDs(values->cl.platform_id, CL_DEVICE_TYPE_GPU, 1,
		&values->cl.device_id, &values->cl.ret_num_devices);
	values->cl.context = clCreateContext(NULL, 1, &values->cl.device_id, NULL,
		NULL, &values->cl.ret);
	values->cl.command_queue = clCreateCommandQueue(values->cl.context,
		values->cl.device_id, 0, &values->cl.ret);
	values->cl.s_mem_obj = clCreateBuffer(values->cl.context, CL_MEM_READ_ONLY,
		sizeof(t_stats), NULL, &values->cl.ret);
	values->cl.c_mem_obj = clCreateBuffer(values->cl.context, CL_MEM_WRITE_ONLY,
		(WIDTH * HEIGHT) * sizeof(int), NULL, &values->cl.ret);
	values->cl.program = clCreateProgramWithSource(values->cl.context, 1,
		(const char **)&values->cl.source_str,
		(const size_t *)&values->cl.source_size, &values->cl.ret);
	clBuildProgram(values->cl.program, 1, &values->cl.device_id,
		"-I includes/", NULL, NULL);
	values->cl.kernel = clCreateKernel(values->cl.program,
		"calc_fractal", &values->cl.ret);
	clSetKernelArg(values->cl.kernel, 0, sizeof(cl_mem),
		(void *)&values->cl.s_mem_obj);
	clSetKernelArg(values->cl.kernel, 1, sizeof(cl_mem),
		(void *)&values->cl.c_mem_obj);
}

void			opencl_calc(t_values *values)
{
	size_t		global_item_size;
	size_t		local_item_size;

	global_item_size = WIDTH * HEIGHT;
	local_item_size = 256;
	clEnqueueWriteBuffer(values->cl.command_queue, values->cl.s_mem_obj,
		CL_TRUE, 0, sizeof(t_stats), &values->stats, 0, NULL, NULL);
	clEnqueueNDRangeKernel(values->cl.command_queue, values->cl.kernel, 1,
		NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
	clEnqueueReadBuffer(values->cl.command_queue, values->cl.c_mem_obj,
		CL_TRUE, 0, (WIDTH * HEIGHT) * sizeof(int),
		values->img_data, 0, NULL, NULL);
}

void			opencl_free(t_values *values)
{
	clFlush(values->cl.command_queue);
	clFinish(values->cl.command_queue);
	clReleaseKernel(values->cl.kernel);
	clReleaseProgram(values->cl.program);
	clReleaseMemObject(values->cl.s_mem_obj);
	clReleaseMemObject(values->cl.c_mem_obj);
	clReleaseCommandQueue(values->cl.command_queue);
	clReleaseContext(values->cl.context);
}
