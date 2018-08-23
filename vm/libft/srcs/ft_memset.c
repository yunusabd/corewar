/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:04:52 by yabdulha          #+#    #+#             */
/*   Updated: 2017/11/20 21:03:57 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	int				i;

	i = 0;
	s = (unsigned char *)b;
	while (len > 0)
	{
		s[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
