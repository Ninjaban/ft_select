/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:52:22 by jcarra            #+#    #+#             */
/*   Updated: 2017/01/03 18:58:18 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

struct termios	g_term;
t_list			*g_list;
t_win			*g_win;
int				g_it;

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

void		ft_sig_check(int signo)
{
	if (signo == SIGKILL || signo == SIGINT || signo == SIGQUIT ||
		signo == SIGTSTP)
	{
		ft_goto("ve", 1, 1);
		ft_goto("clear", 1, 1);
		if (tcsetattr(0, TCSANOW, &g_term) == -1)
			return ;
		if (signo != SIGTSTP)
			exit(1);
		else
			signal(SIGTSTP, SIG_DFL);
	}
	if (signo == SIGCONT)
		if (ft_termcaps_init() == FALSE)
			return ;
	if (signo == SIGWINCH || signo == SIGCONT)
	{
		ft_goto("clear", 1, 1);
		ft_init_size(&g_win);
		if (ft_init_col(&g_win, g_list) == TRUE)
			ft_display(g_win, g_list, g_it);
	}
}

static void	ft_algo(void)
{
	int		exit;

	exit = EXIT_NO;
	g_it = 0;
	ft_display(g_win, g_list, g_it);
	while (exit == EXIT_NO)
	{
		ft_get_input(&g_it, &exit, g_win, &g_list);
		if (!ft_listlen(g_list))
			exit = EXIT_EC;
		if (exit == EXIT_NO)
			ft_display(g_win, g_list, g_it);
	}
	ft_goto("clear", 1, 1);
	if (exit == EXIT_EN)
		ft_print(g_list);
}

void		ft_select(t_list *list)
{
	const char		*name;

	if ((name = getenv("TERM")) == NULL)
		return ;
	if (tgetent(NULL, name) != 1)
		return ;
	if (tcgetattr(0, &g_term) == -1)
		return ;
	if (ft_termcaps_init() == FALSE)
		return ;
	g_win = NULL;
	g_list = list;
	ft_init_size(&g_win);
	while (ft_init_col(&g_win, g_list) == FALSE)
		ft_init_size(&g_win);
	ft_goto("vi", 1, 1);
	ft_algo();
	ft_goto("ve", 1, 1);
	free(g_win);
	ft_free_list(g_list);
	if (tcsetattr(0, TCSANOW, &g_term) == -1)
		return ;
}
