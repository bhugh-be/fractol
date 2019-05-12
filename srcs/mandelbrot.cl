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

__kernel	void	mandelbrot(__global long int *offx, __global long int *offy,
								__global double *scale,  __global int *color, __global const double *iter)
{
	int i = get_global_id(0);
	double	ix = i % 2560;
	double	iy = i / 2560;
	double	cx = 1.5 * ((ix + *offx) / (2560 / 2) - 1.0) / *scale;
	double 	cy = ((iy + *offy) / (1410 / 2) - 1.0) / *scale;
	double	x = cx;
	double	y = cy;
	double	tmp;

	for (int j = 0; j < *iter; ++j)
	{
		if ((sqrt((x * x) + (y * y))) >= 10)
		{
			color[i] = j * 12345678;
			return ;
		}
		tmp = x;
		x = (x * x) - (y * y) + cx;
		y = 2 * tmp * y + cy;
	}
	color[i] = 0;
}
