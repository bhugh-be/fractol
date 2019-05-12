/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:15:11 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/28 17:15:13 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = ft_strnew(len);
	if (!substr)
		return (0);
	if (!s)
		return (0);
	else if (substr)
		ft_memcpy(substr, s + start, len);
	return (substr);
}
