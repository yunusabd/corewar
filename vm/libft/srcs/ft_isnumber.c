/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:18:50 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/07 00:30:41 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if a given string is a number, only allowing minus, plus and spaces.
*/

int		ft_isnumber(char *s)
{
	int	i;

	i = 0;
	if (!s || !(*s))
		return (0);
	while (*s && *s == 32)
		s++;
	if (*s == '-' || *s == '+')
		s++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			i++;
		else if (s[i] == ' ')
		{
			s++;
			if (ft_isdigit(s[i]))
				return (0);
		}
		else
			return (0);
	}
	return ((i) ? 1 : 0);
}
