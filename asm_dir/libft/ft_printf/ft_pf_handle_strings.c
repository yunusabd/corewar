/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_strings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 12:44:42 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_handle_s(va_list args, t_print *features, int *ret)
{
	char	*str;
	char	*new;
	char	*spaces;

	if (!(str = va_arg(args, char*)))
		str = "(null)";
	if (!(new = ft_strdup(str)) ||
		!ft_pf_precision_s(&new, features) ||
		!ft_pf_width_fl_zeros_left(&new, &spaces, features))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	return (1);
}

int		ft_pf_handle_cap_s(va_list args, t_print *features, int *ret)
{
	wchar_t		*str;
	wchar_t		*new;
	wchar_t		*spaces;

	str = va_arg(args, wchar_t*);
	if (!str)
		str = L"(null)";
	if (!(new = ft_wstrdup(str)) ||
	!ft_pf_precision_cap_s(&new, features) ||
	!ft_pf_width_fl_zeros_left_cap_s(&new, &spaces, features))
		return (0);
	*ret = *ret + ft_putwstr(new);
	free(new);
	return (1);
}
