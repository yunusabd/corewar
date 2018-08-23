/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:43:02 by yabdulha          #+#    #+#             */
/*   Updated: 2017/11/29 11:48:53 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;

	while ((*alst) != NULL)
	{
		next = (*alst)->next;
		ft_lstdelone((alst), del);
		(*alst) = next;
	}
}
