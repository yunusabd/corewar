/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:52:42 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 12:49:05 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_precision_s(char **str, t_print *features)
{
	if (features->is_precision && ft_strlen(*str) > features->precision)
		(*str)[features->precision] = '\0';
	return (1);
}

int		ft_pf_precision_cap_s(wchar_t **str, t_print *features)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (features->is_precision && (*str)[i] && len <= features->precision)
	{
		if ((*str)[i] <= 0x7F)
			len++;
		else if ((*str)[i] <= 0x7FF)
			len = len + 2;
		else
			len = len + 3;
		i++;
	}
	i--;
	if (features->is_precision && len > features->precision)
		(*str)[i] = L'\0';
	return (1);
}

int		ft_pf_precision_num(char **str, t_print *features)
{
	char	*spaces;
	char	*new;
	size_t	len;

	if (features->type == 'f' || features->type == 'F')
		return (1);
	if ((*str)[0] == '0' && (features->type == 'x' || features->type == 'X'))
		features->fl_alter = 0;
	(*str)[0] = ((*str)[0] == '0' && (!(features->fl_alter) ||
	features->type == 'p') && features->is_precision) ? '\0' : (*str)[0];
	len = ((*str)[0] == '-' || (*str)[0] == '+')
	? ft_strlen(*str) - 1 : ft_strlen(*str);
	if (features->precision > len)
	{
		if (!(spaces = ft_strnew(features->precision - len)) ||
			!(spaces = ft_strnfill(spaces, '0', (features->precision - len))) ||
			!(new = ft_strjoin(spaces, *str)))
			return (0);
		free(spaces);
		free(*str);
		*str = new;
	}
	if (features->is_precision)
		features->fl_prep_zeros = 0;
	return (1);
}
