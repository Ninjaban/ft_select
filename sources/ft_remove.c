/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:01:52 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/05 16:41:58 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_remove(t_list **list, int it, void (*f)(void *data))
{
	t_list	*tmp;
	t_list	*next;

	if (!list || !(*list) || !f)
		return ;
	tmp = (it == 0) ? ft_listlast(*list) : ft_findit(*list, it - 1);
	next = (tmp->next && tmp->next->next != tmp) ? tmp->next->next : NULL;
	if (tmp->next && ((t_data *)(tmp->next->data)))
		f(tmp->next->data);
	free(tmp->next);
	tmp->next = next;
}
