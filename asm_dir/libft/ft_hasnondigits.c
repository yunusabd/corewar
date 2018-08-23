/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasnondigits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:13:52 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/22 13:59:05 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if every char in a string is a digit. Returns 1 if non-digit is found
*/

int	ft_hasnondigits(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(!i && str[i] == '-' &&
		ft_isdigit(str[i + 1])))
			return (1);
		i++;
	}
	return (0);
}
