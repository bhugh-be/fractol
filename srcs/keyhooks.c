/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:13:35 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/28 14:14:56 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			key_arrows(int keycode, t_values *values)
{
	if (keycode == 126)
		values->stats.offy -= 5;
	else if (keycode == 125)
		values->stats.offy += 5;
	else if (keycode == 123)
		values->stats.offx -= 5;
	else if (keycode == 124)
		values->stats.offx += 5;
}

int				key_press(int keycode, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	if (keycode == 53)
		exit(0);
	else if (keycode == 24)
		values->stats.iter++;
	else if (keycode == 27)
		values->stats.iter--;
	else if (keycode == 18)
		values->stats.color = 1;
	else if (keycode == 19)
		values->stats.color = 2;
	else if (keycode == 20)
		values->stats.color = 3;
	else if (keycode == 30 && values->stats.smooth < 32)
		values->stats.smooth = (values->stats.smooth) ?
			(values->stats.smooth * 2) : (2);
	else if (keycode == 33 && values->stats.smooth)
		values->stats.smooth = (values->stats.smooth == 2) ?
			(values->stats.smooth - 2) : (values->stats.smooth / 2);
	else
		key_arrows(keycode, values);
	draw(values);
	return (0);
}
