/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:52:22 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/01 16:14:45 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

static void		ft_init_size(t_win **win)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	if (*win)
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

void		ft_select(t_list *list)
{
	t_win	*win;

	if (ft_termcaps_init() == FALSE)
		return ;
	win = NULL;
	ft_init_size(&win);
	if (ft_init_col(&win, list) == FALSE)
		return ;
	ft_display(win, list);
	free(win);
	ft_termcaps_end();
}
