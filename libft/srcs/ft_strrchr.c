/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:07:39 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/24 19:07:41 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t l;

	l = ft_strlen((char*)str);
	while (l > 0 && str[l] != (char)ch)
		l--;
	if (str[l] == (char)ch)
		return ((char*)&str[l]);
	return (0);
}
