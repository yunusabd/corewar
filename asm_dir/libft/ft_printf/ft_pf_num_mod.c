/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_num_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 17:00:59 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_num_mod(char **new, char **str, char **spaces, t_print *features)
{
	if (!(*new = ft_strdup(*str)) ||
		!ft_pf_plus_space(new, features) ||
		!ft_pf_precision_num(new, features) ||
		!ft_pf_alter_x(new, features) ||
		!ft_pf_alter_o(new, features) ||
		!ft_pf_width_fl_zeros_left(new, spaces, features) ||
		!ft_pf_alter_x_final(new, features) ||
		!ft_pf_sign(new, features) ||
		!ft_pf_tolower(new, features))
		return (0);
	return (1);
}

int		ft_pf_handle_d(va_list args, t_print *features, int *ret)
{
	long long	c;
	char		*str;
	char		*new;

	if (features->mod == 'H' && !(features->type == 'D'))
		c = (signed char)(va_arg(args, long long int));
	if (features->mod == 'h' && !(features->type == 'D'))
		c = (short)(va_arg(args, long long int));
	if ((features->mod == 'z' || features->mod == 'L')
	&& !(features->type == 'D'))
		c = (va_arg(args, long long));
	if (features->mod == 'j' && !(features->type == 'D'))
		c = (va_arg(args, intmax_t));
	if (features->mod == 'l' || features->type == 'D')
		c = (long int)(va_arg(args, long long int));
	if (!(features->mod) && !(features->type == 'D'))
		c = (va_arg(args, int));
	if ((features->mod == 'H' || features->mod == 'h' || !(features->mod))
	&& !(features->type == 'D'))
		str = ft_itoa(c);
	else
		str = ft_longlongtoa(c);
	return (ft_pf_format_print_num(&new, &str, features, ret)) ? (1) : (0);
}

int		ft_pf_handle_x(va_list args, t_print *features, int *ret)
{
	unsigned long long	c;
	char				*str;
	char				*new;

	if (features->type == 'p' || features->mod == 'L')
		c = va_arg(args, unsigned long long);
	else if (features->mod == 'H')
		c = (unsigned char)(va_arg(args, unsigned long long));
	else if (features->mod == 'h')
		c = (unsigned short)(va_arg(args, unsigned long long));
	else if (features->mod == 'l')
		c = va_arg(args, unsigned long);
	else if (features->mod == 'j')
		c = va_arg(args, uintmax_t);
	else if (features->mod == 'z')
		c = va_arg(args, size_t);
	else
		c = (va_arg(args, unsigned int));
	str = ft_uitoa_base(c, 16);
	return (ft_pf_format_print_num(&new, &str, features, ret)) ? (1) : (0);
}

int		ft_pf_handle_o(va_list args, t_print *features, int *ret)
{
	unsigned long long	c;
	char				*str;
	char				*new;

	if (features->type == 'O' || features->mod == 'l')
		c = va_arg(args, unsigned long);
	else if (features->mod == 'H')
		c = (unsigned char)(va_arg(args, unsigned long long));
	else if (features->mod == 'h')
		c = (unsigned short)(va_arg(args, unsigned long long));
	else if (features->mod == 'L')
		c = va_arg(args, unsigned long long);
	else if (features->mod == 'j')
		c = va_arg(args, uintmax_t);
	else if (features->mod == 'z')
		c = va_arg(args, size_t);
	else
		c = (va_arg(args, unsigned int));
	str = ft_uitoa_base(c, 8);
	return (ft_pf_format_print_num(&new, &str, features, ret)) ? (1) : (0);
}

int		ft_pf_handle_u(va_list args, t_print *features, int *ret)
{
	unsigned long long	c;
	char				*str;
	char				*new;

	if (features->type == 'U' || features->mod == 'l')
		c = va_arg(args, unsigned long);
	else if (features->mod == 'H')
		c = (unsigned char)(va_arg(args, unsigned long long));
	else if (features->mod == 'h')
		c = (unsigned short)(va_arg(args, unsigned long long));
	else if (features->mod == 'L')
		c = va_arg(args, unsigned long long);
	else if (features->mod == 'j')
		c = va_arg(args, uintmax_t);
	else if (features->mod == 'z')
		c = va_arg(args, size_t);
	else
		c = (va_arg(args, unsigned int));
	str = ft_uitoa_base(c, 10);
	return (ft_pf_format_print_num(&new, &str, features, ret)) ? (1) : (0);
}
