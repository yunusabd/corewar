/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:54:19 by yabdulha          #+#    #+#             */
/*   Updated: 2018/04/28 17:55:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Same as ft_strmap, but overwrites the input string with the modified one.
*/

char	*ft_strmap_p(char *s, char (*f)(char))
{
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i] != '\0')
	{
		s[i] = f(s[i]);
		i++;
	}
	return (s);
}
