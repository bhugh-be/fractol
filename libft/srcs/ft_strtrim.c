/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:09:42 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/30 22:09:44 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;
	char	*str;

	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		l = ft_strlen(s) - 1;
		while ((s[l] == ' ' || s[l] == '\t' || s[l] == '\n') && i < l)
			l--;
		str = ft_strsub(s, i, l - i + 1);
		return (str);
	}
	return (0);
}
