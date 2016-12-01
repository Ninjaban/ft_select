/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:33:12 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/01 13:00:21 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "select.h"

t_data		*ft_newd(char *name)
{
	t_data	*new;

	if ((new = malloc(sizeof(t_data))) == NULL)
		return (NULL);
	new->name = ft_strdup(name);
	new->b = FALSE;
	return (new);
}

t_list		*ft_new(void *data)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
