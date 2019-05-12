/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:19:55 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/12 18:38:42 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <errno.h>

#define MAX_SRC_SIZE 100000

char		*get_source(size_t *source_size)
{
	int fd;
	char	*source_str;

	fd = open("srcs/mandelbrot.cl", O_RDONLY);
	if (fd == -1)
		ft_die("kernel is huita");
	source_str = (char *)malloc(MAX_SRC_SIZE);
	*source_size = read(fd, source_str, MAX_SRC_SIZE);
	close(fd);
	return (source_str);
}

void		opencl_init(t_values *values)
{
	size_t	source_size;
	char	*source_str;
	cl_int	ret;

	source_str = get_source(&source_size);
	ret = clGetPlatformIDs(1, &values->cl.platform_id, &values->cl.ret_num_platforms);
	printf("1:%d\n", ret);
	ret = clGetDeviceIDs(values->cl.platform_id, CL_DEVICE_TYPE_CPU, 1, &values->cl.device_id, &values->cl.ret_num_devices);
	printf("2:%d\n", ret);
	values->cl.context = clCreateContext(NULL, 1, &values->cl.device_id, NULL, NULL, &ret);
	printf("3:%d\n", ret);
	values->cl.command_queue = clCreateCommandQueue(values->cl.context, values->cl.device_id, 0, &ret);
	printf("4:%d\n", ret);
	values->cl.offx_mem_obj = clCreateBuffer(values->cl.context, CL_MEM_READ_ONLY, sizeof(long int), NULL, &ret);
	printf("5:%d\n", ret);
	values->cl.offy_mem_obj = clCreateBuffer(values->cl.context, CL_MEM_READ_ONLY, sizeof(long int), NULL, &ret);
	printf("6:%d\n", ret);
	values->cl.s_mem_obj = clCreateBuffer(values->cl.context, CL_MEM_READ_ONLY, sizeof(double), NULL, &ret);
	printf("13:%d\n", ret);
	values->cl.c_mem_obj = clCreateBuffer(values->cl.context, CL_MEM_WRITE_ONLY, (WIDTH * HEIGHT * 4) * sizeof(int), NULL, &ret);
	printf("13:%d\n", ret);
	values->cl.i_mem_obj = clCreateBuffer(values->cl.context, CL_MEM_READ_ONLY, sizeof(double), NULL, &ret);
	printf("7:%d\n", ret);
	values->cl.program = clCreateProgramWithSource(values->cl.context, 1,
	   (const char **)&source_str, (const size_t *)&source_size, &ret);
	printf("8:%d\n", ret);
	ret = clBuildProgram(values->cl.program, 1, &values->cl.device_id, NULL, NULL, NULL);
	printf("9:%d\n", ret);
	values->cl.kernel = clCreateKernel(values->cl.program, "mandelbrot", &ret);
	printf("10:%d\n", ret);
	ret = clSetKernelArg(values->cl.kernel, 0, sizeof(cl_mem), (void *)&values->cl.offx_mem_obj);
	printf("11:%d\n", ret);
	ret = clSetKernelArg(values->cl.kernel, 1, sizeof(cl_mem), (void *)&values->cl.offy_mem_obj);
	printf("12:%d\n", ret);
	ret = clSetKernelArg(values->cl.kernel, 2, sizeof(cl_mem), (void *)&values->cl.s_mem_obj);
	printf("13:%d\n", ret);
	ret = clSetKernelArg(values->cl.kernel, 3, sizeof(cl_mem), (void *)&values->cl.c_mem_obj);
	printf("13:%d\n", ret);
	ret = clSetKernelArg(values->cl.kernel, 4, sizeof(cl_mem), (void *)&values->cl.i_mem_obj);
}

void			opencl_calc(t_values *values)
{
	cl_int	ret;
	size_t global_item_size = WIDTH * HEIGHT;
	size_t local_item_size = 30;

	ret = clEnqueueWriteBuffer(values->cl.command_queue, values->cl.offx_mem_obj, CL_TRUE, 0,
		sizeof(double), &values->offx, 0, NULL, NULL);
	printf("14:%d\n", ret);
	ret = clEnqueueWriteBuffer(values->cl.command_queue, values->cl.offy_mem_obj, CL_TRUE, 0,
		sizeof(double), &values->offy, 0, NULL, NULL);
	printf("15:%d\n", ret);
	ret = clEnqueueWriteBuffer(values->cl.command_queue, values->cl.s_mem_obj, CL_TRUE, 0,
		sizeof(double), &values->scale, 0, NULL, NULL);
	printf("15:%d\n", ret);
	ret = clEnqueueWriteBuffer(values->cl.command_queue, values->cl.i_mem_obj, CL_TRUE, 0,
		sizeof(double), &values->iter, 0, NULL, NULL);
	printf("16:%d\n", ret);
	ret = clEnqueueNDRangeKernel(values->cl.command_queue, values->cl.kernel, 1, NULL,
		&global_item_size, &local_item_size, 0, NULL, NULL);
	printf("17:%d\n", ret);
	ret = clEnqueueReadBuffer(values->cl.command_queue, values->cl.c_mem_obj, CL_TRUE, 0,
		(WIDTH * HEIGHT) * sizeof(int), values->img_data, 0, NULL, NULL);
	printf("18:%d\n", ret);
}

void			opencl_free(t_values *values)
{
	clFlush(values->cl.command_queue);
	clFinish(values->cl.command_queue);
	clReleaseKernel(values->cl.kernel);
	clReleaseProgram(values->cl.program);
	clReleaseMemObject(values->cl.offx_mem_obj);
	clReleaseMemObject(values->cl.offy_mem_obj);
	clReleaseMemObject(values->cl.s_mem_obj);
	clReleaseMemObject(values->cl.i_mem_obj);
	clReleaseMemObject(values->cl.c_mem_obj);
	clReleaseCommandQueue(values->cl.command_queue);
	clReleaseContext(values->cl.context);
}
