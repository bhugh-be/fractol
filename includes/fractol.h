/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:18:48 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/28 15:18:55 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft.h"
# include <mlx.h>
# include <unistd.h>
# include <OpenCL/opencl.h>
# include "struct.h"

# define WIN_NAME "fract'ol"
# define MODULE 80
# define SCALE 1.1

typedef	struct			s_opencl
{
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_uint				ret_num_platforms;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_mem				s_mem_obj;
	cl_mem				c_mem_obj;
	cl_program			program;
	cl_kernel			kernel;
	size_t				source_size;
	char				*source_str;
	cl_int				ret;

}						t_opencl;

struct s_global;

typedef struct			s_values
{
	void				*img_ptr;
	void				*win_ptr;
	char				*img_data;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					fd;
	t_opencl			cl;
	t_stats				stats;
	struct s_global		*global;
}						t_values;

typedef struct			s_global
{
	void				*mlx_ptr;
	int					open_win;
	t_values			*values;
}						t_global;

int						mouse_press(int	button, int x, int y, void *param);
int						mouse_release(int button, int x, int y, void *param);
int						key_press(int keycode, void *param);
int						close_win(void *param);
int						mouse_move(int x, int y, void *param);
void					draw(t_values *values);
int						mandelbrot(t_values values, int *c);
void					set_default(t_values *values);
void					opencl_init(t_values *values);
void					opencl_calc(t_values *values);
void					opencl_free(t_values *values);

#endif
