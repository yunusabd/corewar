/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:29:14 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 13:39:46 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*find_specifier(char *str, t_printf *specs)
{
	while (*(++str))
	{
		if ((ft_strchr(SPECIFIERS, *str)))
			return (str);
		if (!(ft_strchr(VALID_CHARS, *str)))
		{
			specs->converter = '0';
			return (str);
		}
	}
	return (NULL);
}

static int	get_width(t_printf *specs, char *spec_pos)
{
	char	*pos;

	pos = spec_pos;
	while (*(--pos) != '%')
	{
		if (ft_isdigit(*pos) && (!(ft_isdigit(*(pos - 1))))
				&& *(pos - 1) != '.')
		{
			specs->width = ft_atoi(pos);
			return (1);
		}
	}
	return (0);
}

static int	get_precision(t_printf *specs, char *spec_pos)
{
	char	*pos;

	pos = spec_pos;
	while (*(--pos) != '%')
	{
		if (*pos == '.')
		{
			specs->precision = ft_atoi(pos + 1);
			return (1);
		}
	}
	return (0);
}

char		*parse_spec(char *str, t_printf *specs)
{
	char		*pos;
	char		*fstr;
	char		*tmp;

	pos = NULL;
	if (!(pos = find_specifier(str, specs)))
		return (str + 1);
	while ((ft_strchr(VALID_CHARS, *pos)) && !ft_strchr(SPECIFIERS, *pos))
		pos++;
	if (ft_strchr(SPECIFIERS, *pos))
		specs->converter = *pos;
	else
		specs->converter = *pos;
	fstr = ft_strndup(str, pos + 1 - str);
	tmp = fstr;
	fstr = get_flags(fstr, specs);
	if (!(get_width(specs, pos)))
		specs->width = -1;
	if (!(get_precision(specs, pos)))
		specs->precision = -1;
	fstr = get_len(fstr, specs);
	free(tmp);
	if (specs->converter == '0')
		return (pos);
	return (pos + 1);
}
