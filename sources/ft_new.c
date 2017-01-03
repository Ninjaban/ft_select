/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:33:12 by jcarra            #+#    #+#             */
/*   Updated: 2017/01/03 18:51:26 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

t_data		*ft_newd(char *name)
{
	t_data	*new;
	size_t	n;

	if ((new = malloc(sizeof(t_data))) == NULL)
		return (NULL);
	new->type = ft_gettype(name);
	n = 0;
	if (new->type != 0)
	{
		n = ft_strlen(name);
		while (n > 0 && name[n] != '/')
			n = n - 1;
		n = (n == 0) ? n : n + 1;
	}
	new->name = ft_strdup(name + n);
	new->reel = ft_strdup(name);
	new->b = FALSE;
	return (new);
}

t_list		*ft_new(void *data)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
