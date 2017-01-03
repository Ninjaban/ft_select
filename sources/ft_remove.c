/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:01:52 by jcarra            #+#    #+#             */
/*   Updated: 2017/01/03 13:16:13 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_remove(t_list **list, int it, void (*f)(void *data))
{
	t_list	*tmp;
	t_list	*next;

	if (!list || !(*list) || !f)
		return ;
	if (ft_listlen(*list) == 1)
	{
		f((*list)->data);
		free(*list);
		*list = NULL;
		return ;
	}
	tmp = (it == 0) ? ft_listlast(*list) : ft_findit(*list, it - 1);
	*list = (tmp->next == *list) ? (*list)->next : *list;
	next = (tmp->next && tmp->next->next != tmp) ? tmp->next->next : NULL;
	if (tmp->next && ((t_data *)(tmp->next->data)))
		f(tmp->next->data);
	free(tmp->next);
	tmp->next = next;
}
