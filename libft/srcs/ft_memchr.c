/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:55:18 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/23 15:55:20 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c;

	i = 0;
	c = (unsigned char)ch;
	str = (unsigned char *)buf;
	while (i < n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}
