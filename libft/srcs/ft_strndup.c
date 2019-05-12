/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:43:47 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/12/07 16:43:51 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	while (i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
