/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:21:57 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/06 11:37:54 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_wstrlen(const wchar_t *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] <= 0x7F)
			len++;
		else if (s[i] <= 0x7FF)
			len = len + 2;
		else
			len = len + 3;
		i++;
	}
	return (len);
}
