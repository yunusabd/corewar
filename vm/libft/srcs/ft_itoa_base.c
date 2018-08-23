/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:21:28 by yabdulha          #+#    #+#             */
/*   Updated: 2018/04/28 17:31:34 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long value, int base)
{
	char	*buff;
	int		len;
	int		tmp;
	int		minus;

	if (base < 2 || base > 16)
		return (NULL);
	minus = (value < 0 && base == 10) ? 1 : 0;
	len = ft_numlen_ll(value, base);
	tmp = value % base;
	tmp *= (tmp < 0) ? -1 : 1;
	value /= base;
	value *= (value < 0) ? -1 : 1;
	if (!(buff = ft_strnew(len)))
		return (NULL);
	buff[len - 1] = "0123456789ABCDEF"[tmp];
	while (--len)
	{
		buff[len - 1] = "0123456789ABCDEF"[value % base];
		value /= base;
	}
	if (minus)
		buff[0] = '-';
	return (buff);
}
