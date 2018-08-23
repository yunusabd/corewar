/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:55:18 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/04 12:22:15 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_recursive_factorial(int nb)
{
	int x;

	x = nb;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	if (x > 1)
	{
		x = nb * ft_recursive_factorial(nb - 1);
	}
	return (x);
}
