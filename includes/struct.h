/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:01:51 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/14 19:23:43 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 1920
# define HEIGHT 1080
# define MODULE 10
# define MAX_ITER 999

typedef	struct			s_mouse
{
	int					x;
	int					y;
	int					button;
	int					offx;
	int					offy;
}						t_mouse;

typedef	struct			s_stats
{
	long int			offx;
	long int			offy;
	long int			offxl;
	long int			offyl;
	double				scale;
	double				iter;
	int					colors[1000];
	t_mouse				mouse;
}						t_stats;

#endif
