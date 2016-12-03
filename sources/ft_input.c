/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:03:06 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/03 12:54:56 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	ft_check_value(char buf[3], int a, int b, int c)
{
	if ((buf[0] == a || a == -1) &&
		(buf[1] == b || b == -1) &&
		(buf[2] == c || c == -1))
		return (TRUE);
	return (FALSE);
}

static void	ft_set_it(int *it, int set, int len)
{
	(*it) = (*it) + set;
	(*it) = ((*it) >= len) ? (*it) - len : (*it);
	(*it) = ((*it) < 0) ? (*it) + len : (*it);
}

void		ft_get_input(int *it, int *exit, t_win *win, t_list **list)
{
	char	buf[3];

	read(0, buf, 3);
	if (ft_check_value(buf, 27, 91, 65) == TRUE)
		ft_set_it(&(*it), ((int)win->nbcol) * -1, ft_listlen(*list));
	if (ft_check_value(buf, 27, 91, 66) == TRUE)
		ft_set_it(&(*it), (int)win->nbcol, ft_listlen(*list));
	if (ft_check_value(buf, 27, 91, 67) == TRUE)
		ft_set_it(&(*it), 1, ft_listlen(*list));
	if (ft_check_value(buf, 27, 91, 68) == TRUE)
		ft_set_it(&(*it), -1, ft_listlen(*list));
	if (ft_check_value(buf, 27, 91, 70) == TRUE)
		(*exit) = TRUE;
	if (ft_check_value(buf, 32, 0, 0) == TRUE)
	{
		((t_data *)((*list)->data))->b =
			(((t_data *)((*list)->data))->b == TRUE) ? FALSE : TRUE;
		ft_set_it(&(*it), 1, ft_listlen(*list));
	}
	if (ft_check_value(buf, 10, 91, 68) == TRUE)
		*exit = EXIT_EN;
	if ((ft_check_value(buf, 127, -1, -1) == TRUE) ||
		(ft_check_value(buf, 127, 91, 51) == TRUE))
		ft_remove(&ft_findit(list, *it), &ft_deldata);
}
