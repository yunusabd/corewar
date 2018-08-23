/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:28:47 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 14:11:00 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_format_print_num
	(char **new, char **str, t_print *features, int *ret)
{
	char *spaces;

	if (!(ft_pf_num_mod(new, str, &spaces, features)))
		return (0);
	ft_putstr(*new);
	*ret = *ret + ft_strlen(*new);
	free(*new);
	free(*str);
	return (1);
}
