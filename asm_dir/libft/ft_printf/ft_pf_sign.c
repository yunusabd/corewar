/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/15 14:09:37 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_hex_sign(char **str)
{
	const char	*hex = "0X";
	char		*tmp;

	if (!(tmp = ft_strjoin(hex, *str)))
		return (0);
	free(*str);
	*str = tmp;
	return (1);
}

int		ft_pf_hex_sign_zeros(char **str)
{
	if ((*str)[1] == '0' && (*str)[2] != 'X')
	{
		*(ft_strchr(*str, 'X')) = '0';
		(*str)[1] = 'X';
	}
	return (1);
}

int		ft_pf_sign(char **str, t_print *features)
{
	if (ft_strchr(*str, '-'))
	{
		*(ft_strchr(*str, '-')) = '0';
		*(ft_strchr(*str, '0')) = '-';
	}
	else if (ft_strchr(*str, '+') && features->fl_signed_num)
	{
		*(ft_strchr(*str, '+')) = '0';
		*(ft_strchr(*str, '0')) = '+';
	}
	else if (ft_strchr(*str, '+') && features->fl_sign_space)
	{
		*(ft_strchr(*str, '+')) = '0';
		*(ft_strchr(*str, '0')) = ' ';
	}
	return (1);
}

int		ft_pf_plus_space(char **str, t_print *features)
{
	char *tmp;

	if ((features->fl_signed_num || features->fl_sign_space) &&
	!ft_strchr(*str, '-') && features->type != 'o' && features->type != 'O'
	&& features->type != 'u' && features->type != 'U' && features->type != 'x'
	&& features->type != 'X' && features->type != 'p')
	{
		if (!(tmp = ft_strjoin("+", *str)))
			return (0);
		free(*str);
		*str = tmp;
	}
	return (1);
}
