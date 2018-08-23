/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:35:42 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 20:10:36 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_u(unsigned long long value, int base)
{
	char	*buff;
	char	*digits;
	int		len;
	int		tmp;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_numlen_umax(value, base);
	tmp = value % base;
	tmp *= (tmp < 0) ? -1 : 1;
	value /= base;
	if (!(buff = ft_strnew(len)))
		return (NULL);
	digits = "0123456789ABCDEF";
	buff[len - 1] = digits[tmp];
	while (--len && value)
	{
		buff[len - 1] = digits[value % base];
		value /= base;
	}
	return (buff);
}
