/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:01:52 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/05 13:55:33 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_remove(t_list **list, int it, void (*f)(void *data))
{
	t_list	*tmp;

	if (!list || !(*list) || !f)
		return ;
	tmp = *list;
	while (tmp && it > 1)
	{
		it = it - 1;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	tmp->next = (tmp->next && tmp->next != tmp) ? tmp->next->next : NULL;
	if (tmp->next && ((t_data *)(tmp->next->data)))
		f(tmp->next->data);
	free(tmp->next);
	tmp = NULL;
}
