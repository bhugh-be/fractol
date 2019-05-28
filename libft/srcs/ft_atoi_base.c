/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 04:33:20 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/23 16:13:29 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi_base(char *str, int base)
{
	long long int	num;

	num = 0;
	while (ft_isspace(*str))
		str++;
	while ((*str >= '0' && *str <= '9') ||
		(*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))
	{
		if (*str >= '0' && *str <= '9')
			num = num * base + *str - '0';
		if (*str >= 'a' && *str <= 'f')
			num = num * base + *str - 'a' + 10;
		if (*str >= 'A' && *str <= 'F')
			num = num * base + *str - 'A' + 10;
		str++;
	}
	return (num);
}
