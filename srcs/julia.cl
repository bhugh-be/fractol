/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.cl                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:33:07 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/08 17:27:59 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

__kernel	void	calc_fractal(__global t_stats *stats, __global int *color)
{
	int i = get_global_id(0);
	double	ix = i % WIDTH;
	double	iy = i / WIDTH;
	double	cx = 1.5 * ((ix + stats->offx) / (WIDTH / 2) - 1.0) / stats->scale;
	double 	cy = ((iy + stats->offy) / (HEIGHT / 2) - 1.0) / stats->scale;
	double	x = cx;
	double	y = cy;
	double	tmp;

	for (int j = 0; j < stats->iter; ++j)
	{
		if ((sqrt((x * x) + (y * y))) >= MODULE)
		{
			color[i] = (int)(j  * 255 / stats->iter);
			return ;
		}
		tmp = x;
		x = (x * x) - (y * y) + (double)stats->offxl / WIDTH;
		y = 2 * tmp * y + (double)stats->offyl / HEIGHT;
	}
	color[i] = 0;
}
