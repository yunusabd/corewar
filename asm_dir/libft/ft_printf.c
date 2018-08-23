/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:59:10 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 17:35:00 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_pf_format(t_print *features, va_list args, int *ret)
{
	char t;

	t = features->type;
	if (t == 'S' || t == 's')
		return (ft_pf_handle_strings(ret, args, features));
	if (t == 'p')
		return (ft_pf_handle_pointers(ret, args, features));
	if (t == 'd' || t == 'D' || t == 'i' || t == 'o' || t == 'O' ||
		t == 'u' || t == 'U' || t == 'x' || t == 'X' || t == 'f' || t == 'F')
		return (ft_pf_handle_numbers(ret, args, features));
	if (t == 'c' || t == 'C')
		return (ft_pf_handle_chars(ret, args, features));
	else if (t)
		return (ft_pf_handle_others(features, ret));
	return (1);
}

static int	ft_pf_symbols(char **str, int *ret, va_list args)
{
	t_print		*features;

	if (!(features = (t_print *)malloc(sizeof(*features))) ||
		!ft_pf_struct_init(features) ||
		!ft_stroneleft(str) ||
		!ft_pf_store_flags(str, features) ||
		!ft_pf_store_num_width(str, &(features->width), args, features) ||
		!ft_pf_store_precision(str, features, args) ||
		!ft_pf_store_modifiers(str, features) ||
		!ft_pf_store_type(str, &(features->type)) ||
		!ft_pf_format(features, args, ret))
		return (0);
	free(features);
	return (1);
}

int			ft_pf_print(char **str, int *ret)
{
	ft_putstr(*str);
	*ret = *ret + ft_strlen(*str);
	free(*str);
	return (*ret);
}

int			ft_printf(char *format, ...)
{
	va_list args;
	int		ret;
	char	*out;
	char	*str;

	ret = 0;
	if (!(str = ft_strdup(format)))
		return (-1);
	va_start(args, format);
	while (str[0])
	{
		if (ft_strchlen(str, '%') < 0)
			return (ft_pf_print(&str, &ret));
		if (ft_strchlen(str, '%') > 0 &&
	(!(out = ft_strdiv(&str, out, ft_strchlen(str, '%'))) ||
	!ft_pf_print(&out, &ret)))
			return (-1);
		else if (!ft_pf_symbols(&str, &ret, args))
			return (-1);
	}
	free(str);
	va_end(args);
	return (ret);
}
