/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:01:41 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/14 16:05:11 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fills string with n specified characters.
*/

#include "libft.h"

char	*ft_strnfill(char *str, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
