/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:11:21 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/23 12:52:52 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char			*handle_unicode(wchar_t c)
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

char			*wstring(wchar_t *s)
{
	char	*ret;

	if (!s || (!(ret = ft_strnew(1))))
		return (NULL);
	while (*s)
	{
		ret = ft_strjoinfree(ret, handle_unicode(*s), 3);
		s++;
	}
	return (ret);
}

static void		truncate_wstr(char *str, t_printf *specs)
{
	if ((specs->converter == 'S' || specs->isl == 1) && specs->precision)
	{
		while ((specs->converter == 'S' || specs->isl == 1) &&
				(*(str + specs->precision) & 0xC0) == 0x80)
			specs->precision -= 1;
		ft_strclr(str + specs->precision);
	}
}

char			*convert_s(char *str, t_printf *specs)
{
	char	*tmp;
	int		len;

	if ((int)ft_strlen(str) > specs->precision && specs->precision > 0)
		truncate_wstr(str, specs);
	if (specs->precision == 0)
		str = ft_strdup("");
	else if (specs->precision > 0 && specs->precision < (int)ft_strlen(str))
		str = ft_strndup(str, specs->precision);
	if (specs->width > 0 && specs->width > (int)ft_strlen(str))
	{
		len = specs->width - ft_strlen(str);
		len = (specs->negative) ? (len - 1) : (len);
		if (!(tmp = ft_strnew(len)))
			return (NULL);
		tmp = ft_memset((void*)tmp, (specs->iszero &&
					!specs->isminus) ? '0' : ' ', len);
		if (specs->isminus)
			str = ft_strjoinfree(str, tmp, 3);
		else
			str = ft_strjoinfree(tmp, str, 3);
	}
	return (str);
}
