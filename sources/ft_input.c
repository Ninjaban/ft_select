/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:03:06 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/02 14:37:12 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	ft_check_value(char buf[3], int a, int b, int c)
{
	if (buf[0] == a && buf[1] == b && buf[2] == c)
		return (TRUE);
	return (FALSE);
}

static void	ft_set_it(int *it, int set, int len)
{
	(*it) = (*it) + set;
	(*it) = ((*it) >= len) ? (*it) - len : (*it);
	(*it) = ((*it) < 0) ? (*it) + len : (*it);
}

void		ft_get_input(int *it, int *exit, t_win *win, size_t len)
{
	char	buf[3];

	read(0, buf, 3);
	if (ft_check_value(buf, 27, 91, 65) == TRUE)
		ft_set_it(&(*it), ((int)win->nbcol) * -1, len);
	if (ft_check_value(buf, 27, 91, 66) == TRUE)
		ft_set_it(&(*it), (int)win->nbcol, len);
	if (ft_check_value(buf, 27, 91, 67) == TRUE)
		ft_set_it(&(*it), 1, len);
	if (ft_check_value(buf, 27, 91, 68) == TRUE)
		ft_set_it(&(*it), -1, len);
	if (ft_check_value(buf, 27, 91, 70) == TRUE)
		(*exit) = TRUE;
}
