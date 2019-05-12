/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:08:01 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/21 21:08:26 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *s, size_t n)
{
	size_t i;
	size_t j;
	size_t l;

	l = ft_strlen(s);
	if (l == 0)
		return ((char*)str);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (s[j] == str[i + j] && i + j < n)
		{
			j++;
			if (!(s[j]))
				return ((char*)str + i);
		}
		i++;
	}
	return (0);
}
