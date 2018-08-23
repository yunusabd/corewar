/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:03:12 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/04 16:08:38 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(const int nb)
{
	int result;

	if (!(nb % 2 >= 0))
		return (0);
	result = 1;
	while (result <= nb / result)
	{
		if (result == nb / result && nb % result == 0)
			return (result);
		result++;
	}
	return (0);
}
