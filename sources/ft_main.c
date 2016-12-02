/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:14:04 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/02 10:42:26 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int			main(int ac, char **av)
{
	t_list	*list;

	if (ac > 1)
	{
		ft_initlist(&list, ++av, ac - 1);
		if (!list)
			return (1);
		ft_select(list);
//		ft_free_list(list);
	}
	return (0);
}
