/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:14:04 by jcarra            #+#    #+#             */
/*   Updated: 2017/01/03 13:16:18 by jcarra           ###   ########.fr       */
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
		signal(SIGKILL, ft_sig_check);
		signal(SIGQUIT, ft_sig_check);
		signal(SIGWINCH, ft_sig_check);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGCONT, SIG_IGN);
		ft_select(list);
	}
	return (0);
}
