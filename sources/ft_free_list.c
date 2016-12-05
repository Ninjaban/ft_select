/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:28:00 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/05 12:45:07 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_free_list(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return ;
	ft_listlast(list)->next = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = NULL;
		list = tmp;
	}
}
