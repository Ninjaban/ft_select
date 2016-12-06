/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:03:06 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/06 14:05:07 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	ft_set_it(int *it, int set, int len)
{
	(*it) = (*it) + set;
	(*it) = ((*it) >= len) ? (*it) - len : (*it);
	(*it) = ((*it) < 0) ? (*it) + len : (*it);
}

void		ft_get_input(int *it, int *exit, t_win *win, t_list **list)
{
	int		c;
	read(0, &c, sizeof(int));
	if (c == KEY_UPS)
		ft_set_it(&(*it), ((int)win->nbcol) * -1, ft_listlen(*list));
	if (c == KEY_DOW)
		ft_set_it(&(*it), (int)win->nbcol, ft_listlen(*list));
	if (c == KEY_RIG)
		ft_set_it(&(*it), 1, ft_listlen(*list));
	if (c == KEY_LEF)
		ft_set_it(&(*it), -1, ft_listlen(*list));
	if (c == KEY_ESC)
		(*exit) = EXIT_EC;
	if (c == KEY_SPA)
	{
		((t_data *)(ft_findit(*list, (*it))->data))->b =
			(((t_data *)(ft_findit(*list, (*it))->data))->b == TRUE)
			? FALSE : TRUE;
		ft_set_it(&(*it), 1, ft_listlen(*list));
	}
	if (c == KEY_RET)
		*exit = EXIT_EN;
	if (c == KEY_DEL || c == KEY_BAC)
		ft_remove(&(*list), *it, &ft_deldata);
	ft_set_it(&(*it), 0, ft_listlen(*list));
}
