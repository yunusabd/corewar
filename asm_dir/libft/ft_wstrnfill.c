/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:01:41 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/14 16:05:11 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fills wide string with n specified characters.
*/

#include "libft.h"

wchar_t	*ft_wstrnfill(wchar_t *str, wchar_t c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
