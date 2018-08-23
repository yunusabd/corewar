/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:26:32 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/04 11:10:47 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int num;

	i = 0;
	neg = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		neg = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	if (neg)
		return (-num);
	else
		return (num);
}
