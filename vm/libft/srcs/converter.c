/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:18:55 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/23 12:53:23 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char			*convert_c(va_list ap, t_printf *specs)
{
	wchar_t	c;
	char	*ret;

	if (specs->converter == 'C' || specs->isl)
	{
		c = va_arg(ap, wchar_t);
		if (!(ret = handle_unicode(c)))
			return (NULL);
		specs->isl = 1;
		specs->precision = -1;
	}
	else
	{
		c = va_arg(ap, int);
		if (!(ret = ft_strnew(1)))
			return (NULL);
		specs->precision = -1;
		ret[0] = c;
	}
	if (c == 0)
		free(ret);
	if (c == 0)
		ret = NULL;
	ret = padding(ret, specs);
	return (ret);
}

/*
** Converts the length of d and i.
*/

static intmax_t	convert_len(va_list ap, t_printf *specs)
{
	intmax_t	nb;

	if (specs->ishh == 1)
		nb = (signed char)(va_arg(ap, int));
	else if (specs->ish == 1)
		nb = (short)(va_arg(ap, int));
	else if (specs->isll == 1)
		nb = (long long)(va_arg(ap, long long int));
	else if (specs->isl == 1)
		nb = (long)(va_arg(ap, long));
	else if (specs->isj == 1)
		nb = (intmax_t)(va_arg(ap, intmax_t));
	else if (specs->isz == 1)
		nb = (size_t)(va_arg(ap, size_t));
	else
		nb = (int)(va_arg(ap, int));
	nb = (intmax_t)nb;
	return (nb);
}

static char		*p_padding(char *ret, t_printf *specs)
{
	if (specs->iszero)
	{
		specs->width -= 2;
		ret = padding(ret, specs);
		ret = ft_strjoinfree("0x", ret, 2);
	}
	else if (specs->width == -1 || specs->precision > specs->width)
	{
		ret = padding(ret, specs);
		ret = ft_strjoinfree("0x", ret, 2);
	}
	else
	{
		ret = ft_strjoinfree("0x", ret, 2);
		ret = padding(ret, specs);
	}
	return (ret);
}

char			*convert_p(va_list ap, t_printf *specs)
{
	char			*ret;
	intmax_t		nb;

	nb = va_arg(ap, intmax_t);
	if (specs->precision == 0)
		ret = ft_strdup("");
	else
		ret = ft_itoa_base_u(nb, 16);
	specs->isplus = 0;
	if ((int)ft_strlen(ret) < specs->width ||
			(int)ft_strlen(ret) < specs->precision)
		ret = p_padding(ret, specs);
	else
	{
		if ((int)ft_strlen(ret) < (specs->width -= 2))
			ret = padding(ret, specs);
		ret = ft_strjoinfree("0x", ret, 2);
	}
	ret = ft_strmap_p(ret, ft_tolowercase);
	return (ret);
}

char			*convert_d(va_list ap, t_printf *specs)
{
	char			*ret;
	intmax_t		nb;

	nb = convert_len(ap, specs);
	if (!(specs->isl || specs->isll || specs->isj) && nb == -2147483648)
		return (ft_strdup("-2147483648"));
	specs->negative = (nb < 0) ? 1 : 0;
	nb < 0 ? nb = -nb : 0;
	ret = ft_itoa_base(nb, 10);
	if (specs->width > 0 && specs->precision > 0 && !specs->isminus)
		specs->iszero = 0;
	if (ft_strchr(ret, '-'))
		specs->negative = 0;
	ret = padding(ret, specs);
	if (specs->precision == 0 && nb == 0)
	{
		free(ret);
		ret = (padding(ft_strdup(""), specs));
	}
	if (specs->iszero == 1 && specs->isspace == 1 && specs->negative != 1)
		ret[0] = ' ';
	if (!specs->negative && !specs->isplus &&
			specs->isspace && ft_atoi(ret) >= 0)
		ret = ft_strjoinfree((ret[0] != ' ') ? " " : "", ret, 2);
	return (ret);
}
