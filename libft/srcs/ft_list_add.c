/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:59:48 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/07 00:41:09 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void          ft_list_add(t_list **begin, void *data)
{
    t_list      *tmp;
    t_list      *new;

    if (!(new = ft_list_new(data)))
        return ;
    if (!(*begin))
        *begin = new;
    else
    {
        tmp = *begin;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}