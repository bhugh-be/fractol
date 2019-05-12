/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:33:07 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/08 17:27:59 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

__kernel	void	mandelbrot(__global t_stats *stats, __global int *color)
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
			color[i] = j * 98765432;
			return ;
		}
		tmp = x;
		x = (x * x) - (y * y) + cx;
		y = 2 * tmp * y + cy;
	}
	color[i] = 0;
}
