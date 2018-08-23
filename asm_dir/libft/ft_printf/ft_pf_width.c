/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:03:32 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/12 15:52:51 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int	ft_pf_width_fl_zeros_left(char **str, char **spaces, t_print *features)
{
	char	*tmp;

	if (features->width > ft_strlen(*str))
	{
		if (!((*spaces) = ft_strnew(features->width - ft_strlen(*str))))
			return (0);
		*spaces = (features->fl_prep_zeros) ?
			ft_strnfill(*spaces, '0', features->width - ft_strlen(*str)) :
			ft_strnfill(*spaces, ' ', features->width - ft_strlen(*str));
		tmp = (features->fl_left_just) ? ft_strjoin(*str, *spaces) :
			ft_strjoin(*spaces, *str);
		free(*str);
		free(*spaces);
		*str = tmp;
	}
	return (*str) ? (1) : (0);
}

int	ft_pf_width_fl_zeros_left_null_c(char **spaces, t_print *features)
{
	if (features->width > 1)
	{
		if (!((*spaces) = ft_strnew(features->width - 1)))
			return (0);
		*spaces = (features->fl_prep_zeros) ?
			ft_strnfill(*spaces, '0', features->width - 1) :
			ft_strnfill(*spaces, ' ', features->width - 1);
		if (features->fl_left_just)
			ft_putchar('\0');
		ft_putstr(*spaces);
	}
	else
		*spaces = ft_strnew(0);
	if (!(features->fl_left_just) || !(features->width))
		ft_putchar('\0');
	return (*spaces) ? (1) : (0);
}

int	ft_pf_width_fl_zeros_left_cap_s
	(wchar_t **str, wchar_t **spaces, t_print *features)
{
	wchar_t *tmp;

	tmp = NULL;
	if ((int)features->width > ft_wstrlen(*str))
	{
		if (!((*spaces) = ft_wstrnew((int)features->width - ft_wstrlen(*str))))
			return (0);
		*spaces = (features->fl_prep_zeros) ?
	ft_wstrnfill(*spaces, L'0', (int)features->width - ft_wstrlen(*str)) :
	ft_wstrnfill(*spaces, L' ', (int)features->width - ft_wstrlen(*str));
		if (!ft_wstrlen(*str))
			tmp = ft_wstrdup(*spaces);
		else if (features->fl_left_just &&
	!(tmp = ft_wstrjoin(*str, *spaces)))
			return (0);
		else if (!(features->fl_left_just) &&
	!(tmp = ft_wstrjoin(*spaces, *str)))
			return (0);
		free(*str);
		free(*spaces);
		if (!(*str = ft_wstrdup(tmp)))
			return (0);
		free(tmp);
	}
	return (1);
}
