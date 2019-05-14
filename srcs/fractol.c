/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:17:01 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/14 21:51:16 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_default(t_values *values)
{
	values->stats.scale = 1;
	values->stats.offx = 0;
	values->stats.offy = 0;
	values->stats.offxl = 745;
	values->stats.offyl = 683;
	values->stats.iter = 30;
	values->stats.color = 1;
}

t_values		*initialize()
{
	t_values	*values;
	int			i;

	values = (t_values *)ft_memalloc(sizeof(t_values));
	values->mlx_ptr = mlx_init();
	values->win_ptr = mlx_new_window(values->mlx_ptr, WIDTH, HEIGHT, WIN_NAME);
	values->img_ptr = mlx_new_image(values->mlx_ptr, WIDTH, HEIGHT);
	values->img_data = mlx_get_data_addr(values->img_ptr,
		&values->bits_per_pixel, &values->size_line, &values->endian);
	mlx_hook(values->win_ptr, 2, 0, key_press, values);
	mlx_hook(values->win_ptr, 4, 0, mouse_press, values);
	mlx_hook(values->win_ptr, 5, 0, mouse_release, values);
	mlx_hook(values->win_ptr, 6, 0, mouse_move, values);
	mlx_hook(values->win_ptr, 17, 0, close_win, values);
	i = 0;
	while (i < 999)
	{
		values->stats.colors[i + 0] = 0x1B032C;
		values->stats.colors[i + 1] = 0xEBEB7D;
		values->stats.colors[i + 2] = 0x3F576D;
		// values->stats.colors[i + 3] = 0xD3BE9F;
		i += 3;
	}
	return (values);
}

void			draw(t_values *values)
{
	opencl_calc(values);
	mlx_clear_window(values->mlx_ptr, values->win_ptr);
	mlx_put_image_to_window(values->mlx_ptr, values->win_ptr,
		values->img_ptr, 0, 0);
}

int			main(int ac, char **av)
{
	t_values	*values;
	char		*path;

	if (ac != 2)
		ft_die("usage: fractol mandelbrot | julia");
	path = ft_strjoin("srcs/", av[1], 0);
	path = ft_strjoin(path, ".cl", 1);
	values = initialize();
	if ((values->fd = open(path, O_RDONLY)) == -1)
		ft_die("fractal is huita");
	opencl_init(values);
	set_default(values);
	draw(values);
	return (mlx_loop(values->mlx_ptr));
}
