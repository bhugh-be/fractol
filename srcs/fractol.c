/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:17:01 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/23 19:13:29 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_default(t_values *values)
{
	values->stats.scale = 1;
	values->stats.offx = 0;
	values->stats.offy = 0;
	values->stats.offxl = -412;
	values->stats.offyl = 745;
	values->stats.iter = 100;
	values->stats.color = 3;
	values->stats.smooth = 0;
}

void			initialize(t_values *values, char *f_name, void *mlx_ptr)
{
	f_name = ft_strjoin("srcs/", f_name, 0);
	f_name = ft_strjoin(f_name, ".cl", 1);
	if ((values->fd = open(f_name, O_RDONLY)) == -1)
		ft_die("fractal is huita");
	values->mlx_ptr = mlx_ptr;
	values->win_ptr = mlx_new_window(values->mlx_ptr, WIDTH, HEIGHT, WIN_NAME);
	values->img_ptr = mlx_new_image(values->mlx_ptr, WIDTH, HEIGHT);
	values->img_data = mlx_get_data_addr(values->img_ptr,
		&values->bits_per_pixel, &values->size_line, &values->endian);
	mlx_hook(values->win_ptr, 2, 0, key_press, values);
	mlx_hook(values->win_ptr, 4, 0, mouse_press, values);
	mlx_hook(values->win_ptr, 5, 0, mouse_release, values);
	mlx_hook(values->win_ptr, 6, 0, mouse_move, values);
	mlx_hook(values->win_ptr, 17, 0, close_win, values);
	values->stats.colors[0] = 0x1B032C;
	values->stats.colors[1] = 0xEBEB7D;
	values->stats.colors[2] = 0x3F576D;
}

void			draw(t_values *values)
{
	opencl_calc(values);
	mlx_clear_window(values->mlx_ptr, values->win_ptr);
	mlx_put_image_to_window(values->mlx_ptr, values->win_ptr,
		values->img_ptr, 0, 0);
}

int				main(int ac, char **av)
{
	t_global	global;
	int			i;

	if (ac < 2)
		ft_die("usage: fractol mandelbrot2 | mandelbrot4 | julia2 | julia4 | burning_ship | biomorph [...]");
	global.values = (void *)ft_memalloc(sizeof(t_values) * (ac - 1));
	global.mlx_ptr = mlx_init();
	i = 0;
	while (i < ac - 1)
	{
	printf("p0: %p\n", &global.values[i]);
		initialize(&global.values[i], av[i + 1], global.mlx_ptr);
	printf("p1: %p\n", &global.values[i]);
	printf("fd : %d\n", global.values[i].fd);
		printf("%p : %p \n", global.values[i].mlx_ptr, global.values[i].win_ptr);
		opencl_init(&global.values[i]);
		printf("%p : %p \n", global.values[i].mlx_ptr, global.values[i].win_ptr);
		set_default(&global.values[i]);
		draw(&global.values[i]);
		i++;
	}
	return (mlx_loop(global.values->mlx_ptr));
}
