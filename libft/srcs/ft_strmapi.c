/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:27:16 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/29 17:27:18 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*newstr;
	unsigned int	j;

	if (!s || !f)
		return (0);
	newstr = ft_strnew(ft_strlen(s));
	if (!newstr)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		newstr[i] = (*f)(j, s[i]);
		i++;
		j++;
	}
	return (newstr);
}
