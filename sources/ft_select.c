/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:52:22 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/02 16:06:58 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

static void		ft_init_size(t_win **win)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	if (*win && ((*win)->col == window.ws_col && (*win)->row == window.ws_row))
		return ;
	if (*win && ((*win)->col != window.ws_col || (*win)->row != window.ws_row))
		free(win);
	if ((*win = malloc(sizeof(t_win))) == NULL)
		return ;
	(*win)->col = window.ws_col;
	(*win)->row = window.ws_row;
	(*win)->nbcol = 1;
}

static int	ft_init_col(t_win **win, t_list *list)
{
	size_t	max;

	if (!(*win))
		return (FALSE);
	max = ft_get_maxsize(list);
	(*win)->sizecol = ((*win)->col > max + 2) ? max + 2 : (*win)->col;
	while ((*win)->row * (*win)->nbcol <= ft_listlen(list))
		(*win)->nbcol = (*win)->nbcol + 1;
	while ((*win)->sizecol * (*win)->nbcol > (*win)->col)
		(*win)->sizecol = (*win)->sizecol - 1;
	if ((*win)->sizecol == 0)
	{
		free((*win));
		return (FALSE);
	}
	return (TRUE);
}

static void	ft_algo(t_list *list, t_win *win)
{
	size_t	n;
	int		it;
	int		exit;

	n = 0;
	exit = FALSE;
	it = 0;
	ft_display(win, list, it);
	while (exit == FALSE)
	{
		ft_init_size(&win);
		while (ft_init_col(&win, list) == FALSE)
			ft_init_size(&win);
		ft_get_input(&it, &exit, win, ft_listlen(list));
		if (exit == FALSE)
			ft_display(win, list, it);
	}
}

void		ft_select(t_list *list)
{
	t_win	*win;

	if (ft_termcaps_init() == FALSE)
		return ;
	win = NULL;
	ft_init_size(&win);
	ft_init_col(&win, list);
	ft_algo(list, win);
	free(win);
	ft_termcaps_end();
}
