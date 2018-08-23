/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:50:11 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/04 11:30:07 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *array;
	int i;

	if (!(array = malloc(sizeof(*array) * length)))
		return (NULL);
	i = 0;
	while (i < length)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
