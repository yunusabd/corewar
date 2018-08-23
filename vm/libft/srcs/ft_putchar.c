/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:17:02 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 20:11:05 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_unicode(wchar_t c)
{
	char	*str;

	if (!(str = ft_strnew(4)))
		return (NULL);
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) + 0xC0;
		str[1] = (c & 0x3F) + 0x80;
	}
	else if (c < 0xFFFF)
	{
		str[0] = (c >> 12) + 0xE0;
		str[1] = ((c >> 6) & 0x3F) + 0x80;
		str[2] = (c & 0x3F) + 0x80;
	}
	else
	{
		str[0] = ((c >> 18) + 0xF0);
		str[1] = ((c >> 12) & 0x3F) + 0x80;
		str[2] = ((c >> 6) & 0x3F) + 0x80;
		str[3] = (c & 0x3F) + 0x80;
	}
	return (str);
}

void		ft_putchar(wchar_t c)
{
	if (c < 0X80)
		write(1, &c, 1);
	else
		write(1, handle_unicode((wchar_t)c), 4);
}
