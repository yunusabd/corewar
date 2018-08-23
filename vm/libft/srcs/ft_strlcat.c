/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:19:18 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/05 21:06:24 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = ft_strlen(dst);
	len = (i > size) ? (size + ft_strlen(src))
		: (ft_strlen(dst) + ft_strlen(src));
	if (size == 0)
		return (len);
	while (i + 1 < size && i < len)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return ((size_t)len);
}
