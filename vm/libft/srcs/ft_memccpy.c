/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:50:31 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/01 17:50:56 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	unsigned char		*source;
	size_t				i;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n)
	{
		dest[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (dest + (i + 1));
		n--;
		i++;
	}
	return (NULL);
}
