/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:45:16 by yabdulha          #+#    #+#             */
/*   Updated: 2018/03/05 02:13:52 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the length of a number, with an additional space for the '-' for
** negative numbers.
*/

#include "libft.h"

int		ft_numlen(int nb, int base)
{
	int	len;

	if (base < 2)
		return (0);
	len = (nb < 0) ? 2 : 1;
	while ((nb /= base))
		len++;
	return (len);
}
