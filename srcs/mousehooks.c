/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:37:34 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/28 15:17:11 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			mouse_wheel(int button, int x, int y, t_values *values)
{
	if (button == 4)
	{
		values->stats.scale *= SCALE;
		values->stats.offx += (x - (WIDTH / 2) +
			values->stats.offx) * (SCALE - 1);
		values->stats.offy += (y - (HEIGHT / 2) +
			values->stats.offy) * (SCALE - 1);
		values->stats.iter += (values->stats.iter > MAX_ITER) ? (0) : (0.3);
	}
	if (button == 5)
	{
		values->stats.scale *= 2 - SCALE;
		values->stats.offx -= (x - (WIDTH / 2) +
			values->stats.offx) * (SCALE - 1);
		values->stats.offy -= (y - (HEIGHT / 2) +
			values->stats.offy) * (SCALE - 1);
		values->stats.iter -= (values->stats.iter < 1) ? (0) : (0.3);
	}
}

int				mouse_press(int button, int x, int y, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	values->stats.mouse.x = x;
	values->stats.mouse.y = y;
	if (button == 1)
		values->stats.mouse.button = values->stats.mouse.button | 1;
	else if (button == 2)
		values->stats.mouse.button = values->stats.mouse.button | 2;
	else if (button == 3)
		set_default(values);
	else
		mouse_wheel(button, x, y, values);
	draw(values);
	return (0);
}

int				mouse_release(int button, int x, int y, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	values->stats.mouse.x = x;
	values->stats.mouse.y = y;
	if (button == 1)
		values->stats.mouse.button = values->stats.mouse.button & ~1;
	else if (button == 2)
		values->stats.mouse.button = values->stats.mouse.button & ~2;
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	if (values->stats.mouse.button & 1)
	{
		values->stats.offxl -= x - values->stats.mouse.x;
		values->stats.offyl -= y - values->stats.mouse.y;
		draw(values);
	}
	if (values->stats.mouse.button & 2)
	{
		values->stats.offx -= x - values->stats.mouse.x;
		values->stats.offy -= y - values->stats.mouse.y;
		draw(values);
	}
	values->stats.mouse.x = x;
	values->stats.mouse.y = y;
	return (0);
}

int				close_win(void *param)
{
	t_values	*values;

	values = (t_values *)param;
	mlx_destroy_window(values->global->mlx_ptr, values->win_ptr);
	if (!--values->global->open_win)
		exit(0);
	return (0);
}
