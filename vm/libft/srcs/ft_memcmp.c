/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:59:57 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/03 21:25:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0 || s1 == s2)
		return (0);
	i = 0;
	while (n--)
	{
		if ((const unsigned char)str1[i] != (const unsigned char)str2[i])
		{
			return ((int)((const unsigned char)str1[i]
						- (const unsigned char)str2[i]));
		}
		i++;
	}
	return (0);
}
