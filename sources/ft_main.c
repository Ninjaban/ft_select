/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:14:04 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/06 14:07:35 by jcarra           ###   ########.fr       */
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
		signal(SIGINT, ft_sig_check);
		signal(SIGTSTP, ft_sig_check);
		signal(SIGCONT, ft_sig_check);
		ft_select(list);
		ft_free_list(list);
	}
	return (0);
}
