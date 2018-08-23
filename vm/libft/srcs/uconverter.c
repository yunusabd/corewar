/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:18:55 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/23 12:59:44 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long long		convert_len(va_list ap, const t_printf *specs)
{
	if (specs->isll == 1)
		return ((unsigned long long)va_arg(ap, long long));
	if (specs->isl == 1 || specs->converter == 'U' ||
			specs->converter == 'O')
		return ((unsigned long)va_arg(ap, long));
	if (specs->ishh == 1)
		return ((unsigned char)va_arg(ap, int));
	if (specs->ish == 1)
		return ((unsigned short)va_arg(ap, int));
	if (specs->isj == 1)
		return ((uintmax_t)va_arg(ap, uintmax_t));
	if (specs->isz)
		return ((size_t)va_arg(ap, size_t));
	return ((unsigned int)va_arg(ap, int));
}

char					*convert_u(va_list ap, t_printf *specs)
{
	long long		nb;
	char			*ret;

	nb = convert_len(ap, specs);
	specs->negative = 0;
	specs->isplus = 0;
	if (!(ret = ft_itoa_base_u(nb, 10)))
		return (NULL);
	if (specs->precision == 0 && nb == 0)
		ret = ft_strdup("");
	if (specs->precision > -1 && specs->width > -1)
		specs->iszero = 0;
	ret = padding(ret, specs);
	return (ret);
}

static char				*handle_hash(char *ret, t_printf *specs)
{
	if (!specs->iszero && specs->precision == -1)
		return (ft_strjoinfree("0X", ret, 2));
	else
	{
		if (specs->width != -1 || specs->precision != -1)
		{
			if ((int)ft_strlen(ret) > specs->precision)
			{
				ret = ft_strjoinfree("0X", ret, 2);
				return (padding(ret, specs));
			}
			specs->width -= 2;
			ret = padding(ret, specs);
		}
		return (ft_strjoinfree("0X", ret, 2));
	}
	return (ret);
}

char					*convert_x(va_list ap, t_printf *specs)
{
	long long	nb;
	char		*ret;

	nb = convert_len(ap, specs);
	specs->negative = 0;
	specs->isplus = 0;
	(specs->precision >= 0) ? specs->iszero = 0 : 0;
	if (!(ret = ft_itoa_base_u(nb, 16)))
		return (NULL);
	if (specs->ishash && nb != 0)
		ret = handle_hash(ret, specs);
	if (specs->precision == 0 && nb == 0)
	{
		free(ret);
		ret = ft_strdup("");
	}
	ret = padding(ret, specs);
	if (specs->ishash && ret[1] == '0' && ft_strchr(ret, 'X'))
	{
		*(ft_strchr(ret, 'X')) = '0';
		ret[1] = 'X';
	}
	if (specs->converter == 'x')
		return (ft_strmap_p(ret, ft_tolowercase));
	return (ret);
}

char					*convert_o(va_list ap, t_printf *specs)
{
	long long	nb;
	char		*ret;

	specs->isplus = 0;
	specs->negative = 0;
	nb = convert_len(ap, specs);
	if (!(ret = ft_itoa_base_u(nb, 8)))
		return (NULL);
	if (specs->precision > -1 && specs->width > -1)
		specs->iszero = 0;
	if (specs->precision == 0 && !specs->ishash && nb == 0)
	{
		free(ret);
		ret = ft_strdup("");
	}
	if ((specs->converter == 'o' || specs->converter == 'O')
			&& (specs->ishash && nb != 0))
		ret = ft_strjoinfree("0", ret, 2);
	ret = (padding(ret, specs));
	return (ret);
}
