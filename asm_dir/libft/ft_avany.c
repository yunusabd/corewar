/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avany.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:45:14 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/19 15:21:22 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if any arguments test true with a passed in function.
*/

int		ft_avany(char **argv, int argc, int (*f)(char*))
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (f(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
