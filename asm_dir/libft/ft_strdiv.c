/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 12:59:47 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/02 11:21:34 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Divides a string into two. It takes the address of a source (src) and new
** string that is allocated - n characters are copied from src to new.
*/

char	*ft_strdiv(char **src, char *new, int n)
{
	if (!*src || !(new = ft_strnew(n)))
		return (NULL);
	new = ft_strncpy(new, *src, n);
	*src = ft_memmove(*src, *src + n, ft_strlen(*src) - n + 1);
	return (new);
}
