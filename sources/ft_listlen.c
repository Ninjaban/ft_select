/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:38:37 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/01 14:41:22 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

size_t		ft_listlen(t_list *list)
{
	t_list	*tmp;
	size_t	nb;

	nb = (list) ? 1 : 0;
	tmp = (list) ? list->next : list;
	while (tmp && tmp != list)
	{
		tmp = tmp->next;
		nb = nb + 1;
	}
	return (nb);
}
