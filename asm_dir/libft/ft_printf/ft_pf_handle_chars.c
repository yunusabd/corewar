/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 14:20:21 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_handle_c(va_list args, t_print *features, int *ret)
{
	char	c;
	char	*new;
	char	*spaces;

	c = va_arg(args, int);
	if (!c)
	{
		if (!ft_pf_width_fl_zeros_left_null_c(&spaces, features))
			return (0);
		*ret = *ret + 1 + ft_strlen(spaces);
		free(spaces);
		return (1);
	}
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

int		ft_pf_handle_cap_c(va_list args, t_print *features, int *ret)
{
	wchar_t		c;
	wchar_t		*new;
	wchar_t		*spaces;
	char		*spaces_str;

	c = va_arg(args, long long int);
	if (!c)
	{
		if (!ft_pf_width_fl_zeros_left_null_c(&spaces_str, features))
			return (0);
		*ret = *ret + 1 + ft_strlen(spaces_str);
		free(spaces_str);
		return (1);
	}
	if (!(new = ft_wstrnew(1)))
		return (0);
	new[0] = c;
	if (!ft_pf_width_fl_zeros_left_cap_s(&new, &spaces, features))
		return (0);
	*ret = *ret + ft_putwstr(new);
	free(new);
	return (1);
}
