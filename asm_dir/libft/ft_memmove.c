/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:58:41 by jszabo            #+#    #+#             */
/*   Updated: 2017/11/20 18:21:47 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*to;
	const unsigned char	*fro;
	size_t				i;

	to = (unsigned char *)dst;
	fro = (unsigned char *)src;
	i = 0;
	if (fro < to)
	{
		while (len--)
			to[len] = fro[len];
	}
	else
		ft_memcpy(to, fro, len);
	return (to);
}
