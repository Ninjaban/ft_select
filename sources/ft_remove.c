/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:01:52 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/02 09:43:44 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_remove(t_list **list, void (*f)(void *data))
{
	t_list	*tmp;

	if (!list || !(*list) || !f)
		return ;
	tmp = (*list)->prev;
	tmp->next = (*list)->next;
	(*list)->next->prev = tmp;
	if ((t_data *)((*list)->data))
		f((*list)->data);
	free((*list));
	(*list) = NULL;
}
