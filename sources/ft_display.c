/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:55:54 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/21 13:12:55 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

static void	ft_putstr_lim(char *str, size_t lim)
{
	size_t	len;

	len = ft_strlen(str);
	if (len <= lim)
		ft_putstr_fd(str, 2);
	if (len > lim)
	{
		if (lim < 4)
			write(2, str, lim);
		else
		{
			write(2, str, lim - 3);
			ft_putstr_fd("...", 2);
		}
	}
}

static void	ft_checkit(t_list *list, char b, char *u, char *m)
{
	if (b == TRUE)
		ft_goto(u, 1, 1);
	if (((t_data *)(list->data))->b == TRUE)
		ft_goto(m, 1, 1);
}

void		ft_print(t_list *list)
{
	t_list	*tmp;
	size_t	n;

	n = 0;
	tmp = list;
	while (tmp && (tmp != list || n == 0))
	{
		if (((t_data *)(tmp->data))->b == TRUE)
		{
			if (n == 2)
				ft_putchar(' ');
			ft_putstr(((t_data *)(tmp->data))->name);
			n = 2;
		}
		tmp = tmp->next;
		n = (n == 0) ? 1 : n;
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
	tmp = list;
	x = 0;
	y = 0;
	n = 0;
	ft_goto("clear", 1, 1);
	while (tmp && (tmp != list || n == 0))
	{
		ft_goto("cm", x, y);
		ft_checkit(tmp, (n == (size_t)it) ? TRUE : FALSE, "us", "mr");
		ft_putstr_lim(((t_data *)(tmp->data))->name,
						(win->sizecol >= 5) ? win->sizecol - 2 : win->sizecol);
		ft_checkit(tmp, (n == (size_t)it) ? TRUE : FALSE, "ue", "me");
		x = (++n % win->nbcol == 0) ? 0 : x + win->sizecol;
		y = (n % win->nbcol == 0) ? y + 1 : y;
		tmp = tmp->next;
	}
}
