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

// __kernel	void	calc_fractal(__global t_stats *stats, __global int *color)
// {
// 	int i = get_global_id(0);
// 	double	ix = i % WIDTH;
// 	double	iy = i / WIDTH;
// 	double	cx = 1.5 * ((ix + stats->offx) / (WIDTH / 2) - 1.0) / stats->scale;
// 	double 	cy = ((iy + stats->offy) / (HEIGHT / 2) - 1.0) / stats->scale;
// 	double	x = cx;
// 	double	y = cy;
// 	double	tmp;
// 	double	log_zn;
// 	double	nu;

// 	for (int j = 0; j < 1200; ++j)
// 	{
// 		if ((sqrt((x * x) + (y * y))) >= MODULE)
// 		{
// 			color[i] = (int)(j  * 255 / (stats->iter + 1));
// 			return ;
// 		}
// 		tmp = x;
// 		x = (x * x) - (y * y) + (double)stats->offxl / WIDTH;
// 		y = 2 * tmp * y + (double)stats->offyl / HEIGHT;
// 	}
// 	color[i] = 0xffffff;
// }
int			get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

double		fpart(double n)
{
	return (n - floor(n));
}

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
	double	log_zn;
	double	nu;
	int		color1;
	int		color2;

	for (double j = 0; j < stats->iter; ++j)
	{
		if ((sqrt((x * x) + (y * y))) >= MODULE)
		{
			log_zn = log(x * x + y * y) / 2;
			nu = log(log_zn / log(2.0)) / log(2.0);
			j = j + 1 - nu;
			color1 = stats->colors[(int)floor(j)];
			color2 = stats->colors[(int)floor(j) + 1];
			int blue = get_light(color1 & 255, color2 & 255, fpart(j));
			int green = get_light(color1 >> 8 & 255, color2 >> 8 & 255, fpart(j));
			int red = get_light(color1 >> 16 & 255, color2 >> 16 & 255, fpart(j));
			color[i] = (red << 16) | (green << 8) | blue;
			return ;
		}
		tmp = x;
		// x = (x * x) - (y * y) + (double)stats->offxl / WIDTH;
		// y = 2 * tmp * y + (double)stats->offyl / HEIGHT;
		x = (x * x * x * x) - 6 * (x * x) * (y * y) + (y * y * y * y) + (double)stats->offxl / WIDTH;
		y = 4 * (tmp * tmp * tmp) * y - 4 * tmp * (y * y * y) + (double)stats->offyl / HEIGHT;
	}
	color[i] = 0;
}
