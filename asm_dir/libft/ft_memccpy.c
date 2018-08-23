/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:33:04 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/04 11:32:02 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*fro;
	unsigned char	*to;
	size_t			i;

	fro = (unsigned char *)src;
	to = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		to[i] = fro[i];
		if (fro[i] == (unsigned char)c)
			return (to + i + 1);
		i++;
	}
	return (NULL);
}
