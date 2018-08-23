/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 21:57:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/04/28 17:06:59 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the length of a number, with an additional space for the '-' for
** negative numbers.
*/

#include "libft.h"

int		ft_numlen_max(intmax_t nb, int base)
{
	int	len;

	if (base < 2)
		return (0);
	len = (nb < 0) ? 2 : 1;
	while ((nb /= base))
		len++;
	return (len);
}
