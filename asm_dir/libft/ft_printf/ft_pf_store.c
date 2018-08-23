/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:53:24 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/14 14:56:17 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_store_flags(char **str, t_print *features)
{
	const char	*flags = "-+ 0#";
	int			i;

	i = 0;
	if (!((*str)[0]))
		return (1);
	while ((*str)[i] && ft_strchr(flags, (*str)[i]))
	{
		if ((*str)[i] == '0' && !(features->fl_left_just))
			features->fl_prep_zeros = 1;
		if ((*str)[i] == ' ' && !(features->fl_signed_num))
			features->fl_sign_space = 1;
		if ((*str)[i] == '#')
			features->fl_alter = 1;
		if ((*str)[i] == '+')
			ft_pf_set_signed(features);
		if ((*str)[i] == '-')
			ft_pf_set_left(features);
		i++;
	}
	*str = ft_memmove(*str, *str + i, ft_strlen(*str) - i + 1);
	return (1);
}

int		ft_pf_store_num_width(char **str, size_t *target, va_list args,
	t_print *features)
{
	int num;

	num = 0;
	if (ft_isdigit((*str)[0]))
	{
		*target = ft_atoi(*str);
		*str = ft_memmove(*str, *str + ft_numlen(*target),
	ft_strlen(*str) - ft_numlen(*target) + 1);
	}
	else if ((*str)[0] == '*')
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			features->fl_left_just = 1;
			features->fl_prep_zeros = 0;
			num = -num;
		}
		*target = num;
		*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	}
	if ((*str)[0] == '*' || ft_isdigit((*str)[0]))
		ft_pf_store_num_width(str, target, args, features);
	ft_pf_store_flags(str, features);
	return (1);
}

int		ft_pf_store_precision_arg(char **str, va_list args, t_print *features)
{
	int pr;

	pr = va_arg(args, int);
	features->is_precision = pr < 0 ? 0 : 1;
	features->precision = pr < 0 ? 0 : pr;
	*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	return (1);
}

int		ft_pf_store_precision(char **str, t_print *features, va_list args)
{
	int i;

	i = 0;
	while ((*str)[i] == '.')
		i++;
	if (i)
	{
		features->is_precision = 1;
		*str = ft_memmove(*str, *str + i, ft_strlen(*str) - i + 1);
		if (ft_isdigit((*str)[0]))
			ft_pf_store_num_width(str, &(features->precision), args, features);
		else if ((*str)[0] == '*')
			ft_pf_store_precision_arg(str, args, features);
		else
			features->precision = 0;
		ft_pf_store_precision(str, features, args);
	}
	return (1);
}

int		ft_pf_store_modifiers(char **str, t_print *features)
{
	const char	*mod_chars = "hljz";
	char		*modifiers;
	int			i;

	i = 0;
	modifiers = NULL;
	while ((*str)[i] && ft_strchr(mod_chars, (*str)[i]))
		i++;
	if (!(modifiers = ft_strdiv(str, modifiers, i)))
		return (0);
	if (ft_strchr(modifiers, 'l'))
		features->mod = 'l';
	else if (modifiers[0] == 'h' && modifiers[1] && modifiers[1] == 'h')
		features->mod = 'H';
	else if (modifiers[0] == 'l' && modifiers[1] && modifiers[1] == 'l')
		features->mod = 'L';
	else if (i)
		features->mod = modifiers[0];
	free(modifiers);
	ft_pf_store_flags(str, features);
	return (1);
}
