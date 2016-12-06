/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:53:17 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/06 14:16:52 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_sig_check(int signo)
{
	if (signo == SIGTSTP)
	{
		ft_termcaps_end();
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI);
	}
	if (signo == SIGCONT)
	{
		ft_termcaps_init();
	}
	if (signo == SIGKILL)
		signal(SIGINT, SIG_IGN);
}
