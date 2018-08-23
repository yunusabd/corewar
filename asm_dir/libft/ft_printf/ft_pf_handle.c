/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 17:02:54 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_handle_others(t_print *features, int *ret)
{
	char	c;
	char	*new;
	char	*spaces;

	c = features->type;
	if (!(new = ft_strnew(1)))
		return (0);
	new[0] = c;
	if (!ft_pf_width_fl_zeros_left(&new, &spaces, features))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	return (1);
}

int		ft_pf_handle_strings(int *ret, va_list args, t_print *features)
{
	if (features->type == 's' && features->mod != 'l' &&
	!(ft_pf_handle_s(args, features, ret)))
		return (0);
	if (((features->type == 's' && features->mod == 'l') ||
	features->type == 'S') && !(ft_pf_handle_cap_s(args, features, ret)))
		return (0);
	return (1);
}

int		ft_pf_handle_pointers(int *ret, va_list args, t_print *features)
{
	features->fl_alter = 1;
	return (ft_pf_handle_x(args, features, ret)) ? (1) : (0);
}

int		ft_pf_handle_numbers(int *ret, va_list args, t_print *features)
{
	char t;

	t = features->type;
	if ((t == 'd' || t == 'i' || t == 'D') &&
	!ft_pf_handle_d(args, features, ret))
		return (0);
	if ((t == 'o' || t == 'O') && !ft_pf_handle_o(args, features, ret))
		return (0);
	if ((t == 'u' || t == 'U') && !ft_pf_handle_u(args, features, ret))
		return (0);
	if ((t == 'x' || t == 'X') && !ft_pf_handle_x(args, features, ret))
		return (0);
	if ((t == 'f' || t == 'F') && !ft_pf_handle_f(args, features, ret))
		return (0);
	return (1);
}

int		ft_pf_handle_chars(int *ret, va_list args, t_print *features)
{
	if (features->type == 'c' && features->mod != 'l' &&
	!(ft_pf_handle_c(args, features, ret)))
		return (0);
	if (((features->type == 'c' && features->mod == 'l') ||
	features->type == 'C') && !(ft_pf_handle_cap_c(args, features, ret)))
		return (0);
	return (1);
}
