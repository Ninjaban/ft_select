/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:55:54 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/02 14:31:21 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

static void	ft_putstr_lim(char *str, size_t lim)
{
	size_t	len;

	len = ft_strlen(str);
	if (len <= lim)
		ft_putstr(str);
	if (len > lim)
	{
		if (lim < 4)
			write(1, str, lim);
		else
		{
			write(1, str, lim - 3);
			ft_putstr("...");
		}
	}
}

void		ft_display(t_win *win, t_list *list, int it)
{
	t_list	*tmp;
	size_t	x;
	size_t	y;
	size_t	n;

	if (!list)
		return ;
	tmp = list->next;
	x = 0;
	y = 0;
	n = 0;
	ft_goto("clear", 1, 1);
	ft_goto("cm", x, y);
	if (n == (size_t)it)
		ft_goto("us", x, y);
	ft_putstr_lim(((t_data *)(list->data))->name,
					(win->sizecol >= 5) ? win->sizecol - 2 : win->sizecol);
	if (n == (size_t)it)
		ft_goto("ue", x, y);
	while (tmp && tmp != list)
	{
		x = (++n % win->nbcol == 0) ? 0 : x + win->sizecol;
		y = (n % win->nbcol == 0) ? y + 1 : y;
		ft_goto("cm", x, y);
		if (n == (size_t)it)
			ft_goto("us", x, y);
		ft_putstr_lim(((t_data *)(tmp->data))->name,
						(win->sizecol >= 5) ? win->sizecol - 2 : win->sizecol);
		if (n == (size_t)it)
			ft_goto("ue", x, y);
		tmp = tmp->next;
	}
}
