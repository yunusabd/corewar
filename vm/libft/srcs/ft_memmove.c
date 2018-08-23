/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:42:47 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/01 16:18:23 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dest;
	const unsigned char		*source;

	dest = (unsigned char*)dst;
	source = (const unsigned char*)src;
	if ((unsigned long)dst >= (unsigned long)src)
	{
		while (len > 0)
		{
			len--;
			dest[len] = source[len];
		}
	}
	else
	{
		while (len--)
			*dest++ = *source++;
	}
	return (dst);
}
