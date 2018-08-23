/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 21:18:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/03/11 21:19:01 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the length of a number, with an additional space for the '-' for
** negative numbers.
*/

#include "libft.h"

int		ft_numlen_ll(long long nb, int base)
{
	int	len;

	if (base < 2)
		return (0);
	len = (nb < 0) ? 2 : 1;
	while ((nb /= base))
		len++;
	return (len);
}
