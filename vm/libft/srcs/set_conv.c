/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:26:50 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/23 10:48:22 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*init_d(va_list ap, t_printf *specs)
{
	char	*s;

	if (specs->converter == 'D')
	{
		specs->isl = 1;
		specs->ish = 0;
		specs->ishh = 0;
	}
	s = convert_d(ap, specs);
	return (s);
}

char		*init_s(va_list ap, t_printf *specs)
{
	char	*s;

	if (!ft_strchr(SPECIFIERS, specs->converter))
	{
		if (specs->width >= 0)
			specs->precision = -1;
		s = ft_strdup(&(specs->converter));
	}
	else if (specs->converter == 'S' || specs->isl)
		s = wstring(va_arg(ap, wchar_t*));
	else
		s = ft_strdup(va_arg(ap, char*));
	if (!s)
		s = ft_strdup("(null)");
	s = convert_s(s, specs);
	return (s);
}

char		*handle_percent(t_printf *specs)
{
	specs->precision = -1;
	specs->isplus = 0;
	return (padding(ft_strdup("%\0"), specs));
}

int			empty_string(t_printf *specs, int count)
{
	char	*s;

	specs->precision = 0;
	specs->width--;
	s = padding(ft_strdup(""), specs);
	if (specs->isminus)
	{
		ft_putchar('\0');
		count += ft_putstr(s);
		free(s);
		return (count + 1);
	}
	count += ft_putstr(s);
	free(s);
	ft_putchar('\0');
	return (count + 1);
}
