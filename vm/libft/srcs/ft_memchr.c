/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:23:21 by yabdulha          #+#    #+#             */
/*   Updated: 2017/11/29 14:16:02 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			ch;
	char			*str;
	size_t			i;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (i < n)
	{
		if ((char)str[i] != ch)
			i++;
		else
			return ((void*)str + i);
	}
	return (NULL);
}
