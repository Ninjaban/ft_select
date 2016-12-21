/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:53:17 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/14 13:24:43 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <stdio.h>

void		ft_sig_check(int signo)
{
	printf("                                           %d | %d\n", signo, SIGTSTP);
	if (signo == SIGTSTP)
	{
		ft_termcaps_end();
		signal(SIGTSTP, SIG_DFL);
//		ioctl(0, TIOCSTI);
	}
	if (signo == SIGCONT)
	{
		ft_termcaps_init();
		signal(SIGCONT, SIG_DFL);
	}
	if (signo == SIGKILL)
		signal(SIGINT, SIG_IGN);
}
