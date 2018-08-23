/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:35:03 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/01 13:44:23 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

wchar_t		*ft_wstrnew(int size)
{
	wchar_t	*new;
	int		i;

	i = 0;
	new = (wchar_t *)malloc(sizeof(*new) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size + 1)
	{
		new[i] = L'\0';
		i++;
	}
	return (new);
}
