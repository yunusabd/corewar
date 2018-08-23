/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_umax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:35:25 by yabdulha          #+#    #+#             */
/*   Updated: 2018/03/14 20:22:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the length of a number, with an additional space for the '-' for
** negative numbers.
*/

#include "libft.h"

int		ft_numlen_umax(uintmax_t nb, int base)
{
	int	len;

	if (base < 2)
		return (0);
	len = 1;
	while ((nb /= base))
		len++;
	return (len);
}
