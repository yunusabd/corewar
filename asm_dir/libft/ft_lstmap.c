/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:32:00 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/02 12:03:05 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *node;
	t_list *elem;

	if (!lst)
		return (NULL);
	elem = f(lst);
	new = ft_lstnew(elem->content, elem->content_size);
	if (!new)
		return (NULL);
	lst = lst->next;
	node = new;
	while (lst)
	{
		elem = f(lst);
		new->next = ft_lstnew(elem->content, elem->content_size);
		if (!new->next)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (node);
}
