/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:18:37 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/21 18:18:40 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	long long int	num;
	int				sign;
	long long int	tmp;

	num = 0;
	sign = 1;
	tmp = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		tmp = num;
		num = num * 10 + *str - '0';
		if (num < tmp)
			return (sign == -1 ? 0 : -1);
		str++;
	}
	return (num * sign);
}
