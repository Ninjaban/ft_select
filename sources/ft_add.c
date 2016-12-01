/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:36:02 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/01 13:36:58 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_add(t_list **begin, t_list *new)
{
	if (!begin || !new)
		return ;
	new->next = (*begin);
	if ((*begin))
	{
		if ((*begin)->prev)
		{
			new->prev = (*begin)->prev;
			(*begin)->prev->next = new;
		}
		else
			(*begin)->next = new;
		(*begin)->prev = new;
	}
	else
		(*begin) = new;
}
