/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:48:45 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/28 13:56:43 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int free_s)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (free_s & 1)
		free(s1);
	if (free_s & 2)
		free(s2);
	return (str);
}
