/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:37:34 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/12 18:04:59 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_press(int	button, int x, int y, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	values->mouse.x = x;
	values->mouse.y = y;
	if (button == 1)
		values->mouse.button = values->mouse.button | 1;
	if (button == 2)
		values->mouse.button = values->mouse.button | 2;
	if (button == 3)
		set_default(values);
	if (button == 4)
	{
		values->scale *= SCALE;
		values->offx += (x - (WIDTH / 2) + values->offx) * (SCALE - 1);
		values->offy += (y - (HEIGHT / 2) + values->offy) * (SCALE - 1);
		values->iter += 0.3;
	}
	if (button == 5)
	{
		values->scale *= 2 - SCALE;
		values->offx -= (x - (WIDTH / 2) + values->offx) * (SCALE - 1);
		values->offy -= (y - (HEIGHT / 2) + values->offy) * (SCALE - 1);
		values->iter -= 0.3;
	}
	draw(values);
	return (0);
}

int				mouse_release(int button, int x, int y, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	values->mouse.x = x;
	values->mouse.y = y;
	if (button == 1)
		values->mouse.button = values->mouse.button & ~1;
	if (button == 2)
		values->mouse.button = values->mouse.button & ~2;
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	if (values->mouse.button & 2)
	{
		values->offx -= x - values->mouse.x;
		values->offy -= y - values->mouse.y;
		draw(values);
	}
	values->mouse.x = x;
	values->mouse.y = y;
	return (0);
}

int				key_press(int keycode, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		values->offy -= 5;
	if (keycode == 125)
		values->offy += 5;
	if (keycode == 123)
		values->offx -= 5;
	if (keycode == 124)
		values->offx += 5;
	if (keycode == 24)
		values->iter++;
	if (keycode == 27)
		values->iter--;
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
