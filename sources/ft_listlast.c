/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:03:28 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/05 13:56:20 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_list		*ft_listlast(t_list *begin)
{
	t_list	*last;

	if (!begin)
		return (NULL);
	if (!begin->next)
		return (begin);
	last = begin->next;
	while (last && last->next != begin)
		last = last->next;
	return (last);
}
