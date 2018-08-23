/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:25:10 by yabdulha          #+#    #+#             */
/*   Updated: 2018/04/28 19:12:21 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_atoi(const char *str)
{
	int			i;
	int			negative;
	intmax_t	result;

	i = 0;
	result = 0;
	negative = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		negative = (str[i++] == '-') ? 1 : 0;
	if (!(ft_isdigit(str[i])))
		return (0);
	while (ft_isdigit(str[i]) == 1)
		result = (result * 10 - (str[i++] - '0'));
	if (!negative)
		result = -result;
	if (result > LONG_MAX)
		return (0);
	if (result < LONG_MIN)
		return (0);
	return ((int)result);
}
