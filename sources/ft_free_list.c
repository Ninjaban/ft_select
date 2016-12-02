/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:28:00 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/02 09:42:33 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_free_list(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (list->next)
	{
		tmp = list->next;
		printf("%s\n", ((t_data *)(list->next->data))->name);
		ft_remove(&list->next, &ft_deldata);
	}
	if (list)
		ft_remove(&list, &ft_deldata);
}
