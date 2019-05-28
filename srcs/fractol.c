/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:17:01 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/28 15:59:31 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_default(t_values *values)
{
	values->stats.scale = 1;
	values->stats.offx = 0;
	values->stats.offy = 0;
	values->stats.offxl = -500;
	values->stats.offyl = 500;
	values->stats.iter = 70;
	values->stats.color = 3;
	values->stats.smooth = 0;
}

int				initialize(t_values *values, char *f_name, t_global *global)
{
	f_name = ft_strjoin("srcs/", f_name, 0);
	f_name = ft_strjoin(f_name, ".cl", 1);
	if ((values->fd = open(f_name, O_RDONLY)) == -1)
	{
		ft_putstr("no such file: ");
		ft_putendl(f_name);
		global->open_win--;
		return (1);
	}
	free(f_name);
	values->global = global;
	values->win_ptr = mlx_new_window(values->global->mlx_ptr,
		WIDTH, HEIGHT, WIN_NAME);
	values->img_ptr = mlx_new_image(values->global->mlx_ptr, WIDTH, HEIGHT);
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
	return (0);
}

void			draw(t_values *values)
{
	opencl_calc(values);
	mlx_clear_window(values->global->mlx_ptr, values->win_ptr);
	mlx_put_image_to_window(values->global->mlx_ptr, values->win_ptr,
		values->img_ptr, 0, 0);
}

int				main(int ac, char **av)
{
	t_global	global;
	int			i;

	if (ac < 2)
		ft_die("usage: fractol mandelbrot2 | mandelbrot4 | julia2 | julia4 | "
		"burning_ship | biomorph3 | biomorph9 | huita [...]");
	global.values = (t_values *)ft_memalloc(sizeof(t_values) * (ac - 1));
	global.mlx_ptr = mlx_init();
	global.open_win = ac - 1;
	i = -1;
	while (++i < ac - 1)
	{
		if (initialize(&global.values[i], av[i + 1], &global))
			continue ;
		opencl_init(&global.values[i]);
		set_default(&global.values[i]);
		draw(&global.values[i]);
	}
	if (!global.open_win)
		exit(0);
	return (mlx_loop(global.mlx_ptr));
}
