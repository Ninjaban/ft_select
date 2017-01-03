/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:26:41 by jcarra            #+#    #+#             */
/*   Updated: 2017/01/03 18:08:32 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	ft_isdir(char *name)
{
	struct stat	*buf;

	if ((buf = malloc(sizeof(struct stat))) == NULL)
		return (0);
	if (lstat(name, buf) == -1)
	{
		free(buf);
		return (0);
	}
	if (S_ISDIR(buf->st_mode))
	{
		free(buf);
		return (2);
	}
	free(buf);
	return (0);
}

static int	ft_lnk(char *name)
{
	char	*lnk;

	if ((lnk = malloc(1024)) == NULL)
		return (0);
	if (readlink(name, lnk, 1023) != -1)
	{
		free(lnk);
		return (4);
	}
	free(lnk);
	return (0);
}

int			ft_gettype(char *name)
{
	if (access(name, F_OK))
		return (0);
	if (ft_isdir(name))
		return (2);
	if (ft_lnk(name))
		return (4);
	if (!access(name, X_OK))
		return (3);
	return (1);
}
