/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:43:06 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/28 21:43:08 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*newstr;

	if (!s || !f)
		return (0);
	newstr = ft_strnew(ft_strlen(s));
	if (!newstr)
		return (0);
	i = 0;
	while (s[i])
	{
		newstr[i] = (*f)(s[i]);
		i++;
	}
	return (newstr);
}
