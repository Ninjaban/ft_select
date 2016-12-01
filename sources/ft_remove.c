/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:01:52 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/01 13:03:19 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_remove(t_list **list, void (*f)(void *data))
{
	t_list	*tmp;

	if (!list || !(*list) || !f)
		return ;
	tmp = (*list)->prev;
	(*list)->prev = (*list)->next;
	(*list)->next = tmp;
	if ((t_data *)((*list)->data))
		f((*list)->data);
	free((*list));
}
