/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:17:25 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/04 11:32:50 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*to;
	char	*frm;

	to = (char *)dst;
	frm = (char *)src;
	i = 0;
	while (i < n)
	{
		to[i] = frm[i];
		i++;
	}
	dst = to;
	return (dst);
}
