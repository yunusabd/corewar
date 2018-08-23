/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isalnumsp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:45:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 15:21:22 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if a null-terminated string only contains alphanumeric characters
** and spaces. If true, returns 1, else returns 0.
*/

int	ft_str_isalnumsp(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
