/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:00:14 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/26 23:00:18 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *dest;
	unsigned char *source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (source < dest)
		while (n > 0)
		{
			n--;
			*(dest + n) = *(source + n);
		}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
