/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:31:48 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/23 16:19:59 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_free(t_list *begin, void (*f)(void *))
{
	t_list	*tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		f(tmp->data);
		free(tmp);
	}
}
