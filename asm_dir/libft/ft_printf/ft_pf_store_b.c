/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_store_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:32:46 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/14 14:34:00 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int		ft_pf_store_type(char **str, char *type)
{
	*type = (*str)[0];
	*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	return (1);
}
