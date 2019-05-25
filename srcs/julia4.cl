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

int			get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

double		fpart(double n)
{
	return (n - floor(n));
}

int		gradient_color(__global t_stats *stats, double x, double y, int i)
{
	double	log_zn;
	double	nu;
	int		color1;
	int		color2;

	log_zn = log(x * x + y * y) / 4;
	nu = log(log_zn / log(4.0)) / log(4.0);
	i = i + 1 - nu;
	color1 = stats->colors[i % 3];
	color2 = stats->colors[(i + 1) % 3];
	double j = 1 - nu;
	int blue = get_light(color1 & 255, color2 & 255, fpart(j));
	int green = get_light(color1 >> 8 & 255, color2 >> 8 & 255, fpart(j));
	int red = get_light(color1 >> 16 & 255, color2 >> 16 & 255, fpart(j));
	return((red << 16) | (green << 8) | blue);
}

int			light_color(__global t_stats *stats, int i)
{
	return (((double)i / stats->iter) * 255);
}

int			get_color(__global t_stats *stats, double ix, double iy)
{
	double	cx = 1.5 * ((ix + stats->offx) / (WIDTH / 2) - 1.0) / stats->scale;
	double 	cy = ((iy + stats->offy) / (HEIGHT / 2) - 1.0) / stats->scale;
	double	x = cx;
	double	y = cy;
	double	tmp;

	for (int i = 0; i < stats->iter; ++i)
	{
		if ((sqrt((x * x) + (y * y))) >= MODULE)
		{
			if (stats->color == 1)
				return (0xffffff);
			if (stats->color == 2)
				return (light_color(stats, i));
			if (stats->color == 3)
				return (gradient_color(stats, x, y, i));
		}
		tmp = x;
		x = (x * x * x * x) - 6 * (x * x) * (y * y) + (y * y * y * y) + (double)stats->offxl / WIDTH;
		y = 4 * (tmp * tmp * tmp) * y - 4 * tmp * (y * y * y) + (double)stats->offyl / HEIGHT;
	}
	return(0);
}

__kernel	void	calc_fractal(__global t_stats *stats, __global int *color)
{
	int i = get_global_id(0);
	double	ix = (i % WIDTH);
	double	iy = (i / WIDTH);
	int		red = 0;
	int		green = 0;
	int		blue = 0;
	int		c;

	if (!stats->smooth)
	{
		color[i] = get_color(stats, ix, iy);
		return ;
	}
	for (double i = 0; i < 1; i += 1.0 / stats->smooth)
	{
		for (double j = 0; j < 1; j += 1.0 / stats->smooth)
		{
			c = get_color(stats, ix + i, iy + j);
			red += c >> 16 & 255;
			green += c >> 8 & 255;
			blue += c & 255;
		}
	}
	red /= stats->smooth * stats->smooth;
	green /= stats->smooth * stats->smooth;
	blue /= stats->smooth * stats->smooth;
	color[i] = (red << 16) | (green << 8) | blue;
}
