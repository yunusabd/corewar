/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:36:24 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/01 16:11:43 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	int			i;

	dest = (char*)dst;
	i = 0;
	source = (const char*)src;
	if (n == 0 || dest == source)
		return (dst);
	while (n > 0)
	{
		dest[i] = source[i];
		i++;
		n--;
	}
	return (dst);
}
