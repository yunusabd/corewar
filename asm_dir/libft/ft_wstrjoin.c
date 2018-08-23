/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:10:15 by jszabo            #+#    #+#             */
/*   Updated: 2018/01/05 09:13:33 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

wchar_t	*ft_wstrjoin(const wchar_t *s1, const wchar_t *s2)
{
	wchar_t	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2 || !(new = (wchar_t *)malloc(sizeof(*new) *
	(ft_wstrlen(s1) + ft_wstrlen(s2) + 1))))
		return (NULL);
	while (s1[j])
	{
		new[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = L'\0';
	return (new);
}
