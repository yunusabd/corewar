/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:45:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 15:21:22 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the occurance of a char in a null-terminating string.
*/

int	ft_count_char(char *str, char c)
{
	int i;

	i = 0;
	while (*str)
	{
		if ((*str) == c)
			i++;
		str++;
	}
	return (i);
}
