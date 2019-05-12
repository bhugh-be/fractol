/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:06:33 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/27 22:06:36 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	if (size == (size_t)(-1))
		return (NULL);
	mem = malloc(size + 1);
	if (mem == 0)
		return (NULL);
	else
		ft_bzero(mem, size + 1);
	return (mem);
}
