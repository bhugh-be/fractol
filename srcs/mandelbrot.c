/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:33:07 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/12 16:46:33 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void				set_x_arr(t_values * values)
// {
// 	int 			i;

// 	i = 0;
// 	while (i < WIDTH)
// 	{
// 		values->x_arr[i] = 1.5 * (((double)i + values->offx) / (WIDTH / 2) - 1.0) / values->scale;
// 		++i;
// 	}
// 	i = 1;
// 	while (i < HEIGHT)
// 	{
// 		ft_memcpy(values->x_arr + i * WIDTH, values->x_arr, WIDTH * sizeof(double));
// 		i++;
// 	}
// }

// void				set_y_arr(t_values *values)
// {
// 	int				i;
// 	int				j;
// 	double			tmp;

// 	i = 0;
// 	j = 0;
// 	while (i < HEIGHT)
// 	{
// 		j = 0;
// 		tmp = (((double)i + values->offy) / (HEIGHT / 2) - 1.0) / values->scale;
// 		while (j < WIDTH)
// 		{
// 			values->y_arr[WIDTH * i + j] = tmp;
// 			j++;
// 		}
// 		i++;
// 	}
// }
