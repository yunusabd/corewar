/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:21:10 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/02 12:16:09 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

wchar_t	*ft_wstrdup(wchar_t *s1)
{
	wchar_t *new;

	new = (wchar_t *)malloc(sizeof(*new) * ft_wstrlen(s1) + 1);
	if (!new)
		return (NULL);
	new = ft_wstrcpy(new, s1);
	return (new);
}
