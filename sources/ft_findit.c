/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:00:27 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/05 09:03:30 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_list		*ft_findit(t_list *list, int *it)
{
	t_list	*tmp;
	int		n;

	tmp = list;
	n = 0;
	if (!tmp)
		return (NULL);
	while (tmp && n < *it)
	{
		tmp = tmp->next;
		n = n + 1;
	}
	if (!tmp || n < *it)
		return (NULL);
	else
		return (tmp);
}
