/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_alter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:52:47 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 14:23:59 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_alter(char **str, int alter)
{
	size_t	i;
	char	*new;

	i = 0;
	new = NULL;
	if (!alter)
		return (1);
	while ((*str)[i])
	{
		if ((*str)[i] != ' ' && (*str)[i] != '0')
			break ;
		i++;
	}
	if (i == ft_strlen(*str))
		return (1);
	if (!i)
	{
		if (!(new = ft_strjoin("0", *str)))
			return (0);
		free(*str);
		*str = new;
	}
	if (i > 0)
		(*str)[i - 1] = '0';
	return (1);
}

int		ft_pf_alter_x(char **str, t_print *features)
{
	if ((features->type == 'x' || features->type == 'X'
	|| features->type == 'p') && features->fl_alter && !ft_pf_hex_sign(str))
		return (0);
	return (1);
}

int		ft_pf_alter_x_final(char **str, t_print *features)
{
	if ((features->type == 'x' || features->type == 'X'
	|| features->type == 'p') &&
	features->fl_alter && !ft_pf_hex_sign_zeros(str))
		return (0);
	return (1);
}

int		ft_pf_alter_o(char **str, t_print *features)
{
	char	*alter;

	if ((features->type == 'o' || features->type == 'O') &&
	features->fl_alter && (*str)[0] != '0')
	{
		if (!(alter = ft_strjoin("0", *str)))
			return (0);
		free(*str);
		*str = alter;
	}
	return (1);
}

int		ft_pf_tolower(char **str, t_print *features)
{
	int i;

	i = 0;
	while ((*str)[i] && (features->type == 'x' || features->type == 'p'))
	{
		(*str)[i] = ft_tolower((*str)[i]);
		i++;
	}
	return (1);
}
