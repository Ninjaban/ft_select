/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:52:22 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/27 14:19:30 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

static void	ft_init_size(t_win **win)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	if (*win && ((*win)->col == window.ws_col && (*win)->row == window.ws_row))
		return ;
	if (!(*win) && (*win = malloc(sizeof(t_win))) == NULL)
		return ;
	(*win)->col = window.ws_col;
	(*win)->row = window.ws_row;
	(*win)->nbcol = 1;
}

static int	ft_init_col(t_win **win, t_list *list)
{
	size_t	max;

	if (!win || !(*win))
		return (FALSE);
	max = ft_get_maxsize(list);
	(*win)->sizecol = ((*win)->col > max + 2) ? max + 2 : (*win)->col;
	while ((*win)->row * (*win)->nbcol <= ft_listlen(list))
		(*win)->nbcol = (*win)->nbcol + 1;
	while ((*win)->sizecol * (*win)->nbcol > (*win)->col)
		(*win)->sizecol = (*win)->sizecol - 1;
	if ((*win)->sizecol <= 6 && (max >= (*win)->sizecol))
		return (FALSE);
	return (TRUE);
}

static void	ft_algo(t_list *list, t_win *win)
{
	size_t	n;
	int		it;
	int		exit;

	n = 0;
	exit = EXIT_NO;
	it = 0;
	ft_display(win, list, it);
	while (exit == EXIT_NO)
	{
		ft_init_size(&win);
		while (ft_init_col(&win, list) == FALSE)
			ft_init_size(&win);
		ft_get_input(&it, &exit, win, &list);
		ft_init_size(&win);
		while (ft_init_col(&win, list) == FALSE)
			ft_init_size(&win);
		if (!ft_listlen(list))
			exit = EXIT_EC;
		if (exit == EXIT_NO)
			ft_display(win, list, it);
	}
	ft_goto("clear", 1, 1);
	if (exit == EXIT_EN)
		ft_print(list);
}

void		ft_select(t_list *list)
{
	t_win			*win;

	if (ft_termcaps_init() == FALSE)
		return ;
	win = NULL;
	ft_init_size(&win);
	ft_putnbr(ft_listlen(list));
	while (ft_init_col(&win, list) == FALSE)
		ft_init_size(&win);
	ft_goto("vi", 1, 1);
	ft_algo(list, win);
	ft_goto("ve", 1, 1);
	free(win);
	if (ft_termcaps_init() == FALSE)
		return ;
}
