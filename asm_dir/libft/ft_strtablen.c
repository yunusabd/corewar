/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:45:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/17 15:21:22 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the length of a null-terminated array of strings.
*/

int	ft_strtablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
