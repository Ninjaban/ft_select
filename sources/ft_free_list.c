/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:28:00 by jcarra            #+#    #+#             */
/*   Updated: 2017/01/03 18:55:04 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	ft_free_data(t_data *data)
{
	if (data->name)
		free(data->name);
	if (data->reel)
		free(data->reel);
	free(data);
}

void		ft_free_list(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return ;
	ft_listlast(list)->next = NULL;
	while (list)
	{
		tmp = list->next;
		if (list->data)
			ft_free_data(list->data);
		free(list);
		list = NULL;
		list = tmp;
	}
}
