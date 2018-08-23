/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:39:30 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/03 15:41:55 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dst_len;
	size_t n;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size < dst_len)
		return (ft_strlen(src) + size);
	n = size - dst_len;
	while (n > 1 && src[i] != '\0')
	{
		dst[dst_len] = src[i];
		dst_len++;
		n--;
		i++;
	}
	dst[dst_len] = '\0';
	return (ft_strlen(src) + dst_len - i);
}
