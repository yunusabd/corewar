/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:26:32 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/22 15:57:29 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			i;
	int			neg;
	long long	num;

	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	neg = (str[i] == '-') ? 1 : 0;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	return (neg) ? (-num) : (num);
}
