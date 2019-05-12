/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:46:05 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/21 19:46:07 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *s)
{
	size_t i;
	size_t j;
	size_t l;

	l = ft_strlen(s);
	if (l == 0)
		return ((char*)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (s[j] == str[i + j])
		{
			if (!(s[j + 1]))
				return ((char*)str + i);
			j++;
		}
		i++;
	}
	return (0);
}
