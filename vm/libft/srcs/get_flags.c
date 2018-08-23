/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:29:14 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 13:42:28 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*set_len(char *fstr, int *len_conv, int offset)
{
	*len_conv = 1;
	return (fstr += offset);
}

char		*get_len(char *fstr, t_printf *specs)
{
	if (!fstr)
		return (fstr);
	if (ft_strstr(fstr, "ll") && (specs->isll = 1))
		return (fstr + 2);
	else if (ft_strstr(fstr, "hh") && (specs->ishh = 1))
		return (fstr + 2);
	else if (ft_strstr(fstr, "l"))
		return (set_len(fstr, &specs->isl, 1));
	else if (ft_strstr(fstr, "h"))
		return (set_len(fstr, &specs->ish, 1));
	else if (ft_strstr(fstr, "j"))
		return (set_len(fstr, &specs->isj, 1));
	else if (ft_strstr(fstr, "z"))
		return (set_len(fstr, &specs->isz, 1));
	else
		return (fstr);
}

char		*get_flags(char *fstr, t_printf *new)
{
	while (*(++fstr))
	{
		if (*fstr == '#')
			new->ishash = 1;
		else if (*fstr == '0')
			new->iszero = 1;
		else if (*fstr == '-')
			new->isminus = 1;
		else if (*fstr == ' ')
			new->isspace = 1;
		else if (*fstr == '+')
			new->isplus = 1;
		else
			return (fstr);
	}
	return (fstr);
}
