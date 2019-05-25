/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:37:34 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/15 21:08:31 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_press(int	button, int x, int y, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	values->stats.mouse.x = x;
	values->stats.mouse.y = y;
	if (button == 1)
		values->stats.mouse.button = values->stats.mouse.button | 1;
	if (button == 2)
		values->stats.mouse.button = values->stats.mouse.button | 2;
	if (button == 3)
		set_default(values);
	if (button == 4)
	{
		values->stats.scale *= SCALE;
		values->stats.offx += (x - (WIDTH / 2) + values->stats.offx) * (SCALE - 1);
		values->stats.offy += (y - (HEIGHT / 2) + values->stats.offy) * (SCALE - 1);
		values->stats.iter += (values->stats.iter > MAX_ITER) ? (0) : (0.3);
	}
	if (button == 5)
	{
		values->stats.scale *= 2 - SCALE;
		values->stats.offx -= (x - (WIDTH / 2) + values->stats.offx) * (SCALE - 1);
		values->stats.offy -= (y - (HEIGHT / 2) + values->stats.offy) * (SCALE - 1);
		values->stats.iter -= (values->stats.iter < 1) ? (0) : (0.3);
	}
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
	if (button == 2)
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

int				key_press(int keycode, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		values->stats.offy -= 5;
	if (keycode == 125)
		values->stats.offy += 5;
	if (keycode == 123)
		values->stats.offx -= 5;
	if (keycode == 124)
		values->stats.offx += 5;
	if (keycode == 24)
		values->stats.iter++;
	if (keycode == 27)
		values->stats.iter--;
	if (keycode == 18)
		values->stats.color = 1;
	if (keycode == 19)
		values->stats.color = 2;
	if (keycode == 20)
		values->stats.color = 3;
	if (keycode == 30 && values->stats.smooth < 32)
		values->stats.smooth = (values->stats.smooth) ? (values->stats.smooth * 2) : (2);
	if (keycode == 33 && values->stats.smooth)
		values->stats.smooth = (values->stats.smooth == 2) ? (values->stats.smooth - 2) : (values->stats.smooth / 2);
	draw(values);
	return (0);
}

int				close_win(void *param)
{
	t_values	*values;

	values = (t_values *)param;
	free(values);
    exit(0);
}
