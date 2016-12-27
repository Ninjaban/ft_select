/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:53:17 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/27 14:41:09 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"
#include <stdio.h>

void		ft_sig_check(int signo)
{
	if (signo == SIGKILL)
	{
		ft_goto("ve", 1, 1);
		ft_termcaps_init();
		exit(1);
	}
	if (signo == SIGINT)
	{
		ft_goto("ve", 1, 1);
		ft_termcaps_init();
		exit(1);
	}
	if (signo == SIGQUIT)
	{
		ft_goto("ve", 1, 1);
		ft_termcaps_init();
		exit(1);
	}
}
