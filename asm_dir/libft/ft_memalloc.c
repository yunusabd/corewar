/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:53:33 by jszabo            #+#    #+#             */
/*   Updated: 2017/11/21 17:06:22 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = malloc(sizeof(a) * size);
	if (!a)
		return (NULL);
	while (i < size)
	{
		a[i] = '\0';
		i++;
	}
	return ((void *)a);
}
