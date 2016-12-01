/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:31:00 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/01 16:06:59 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

size_t		ft_get_maxsize(t_list *list)
{
	t_list	*tmp;
	size_t	max;

	tmp = list->next;
	max = ft_strlen(((t_data *)(list->data))->name);
	while (tmp && tmp != list)
	{
		if (ft_strlen(((t_data *)(list->data))->name) > max)
			max = ft_strlen(((t_data *)(list->data))->name);
		tmp = tmp->next;
	}
	return (max);
}
