/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:42:15 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/04 12:17:45 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*a;

	i = 0;
	a = (char *)b;
	while (i < len)
	{
		a[i] = (char)c;
		i++;
	}
	return ((void *)a);
}
