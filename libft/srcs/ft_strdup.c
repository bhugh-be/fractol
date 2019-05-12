/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:19:05 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/21 19:19:07 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	str = (char*)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (0);
	j = 0;
	while (j < i)
	{
		str[j] = src[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}
