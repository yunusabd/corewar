/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:56:29 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/04 11:23:03 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static	size_t	ft_count_words(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			j++;
		i++;
	}
	if (s[0] != c)
		j++;
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**arr;
	unsigned int	i;
	unsigned int	j;
	size_t			k;

	i = 0;
	k = 0;
	if (!s || !(arr = (char **)malloc(sizeof(*arr) *
	(ft_count_words(s, c) + 1))))
		return (NULL);
	while (k < ft_count_words(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			j++;
			i++;
		}
		arr[k] = ft_strsub(s, i - j, j);
		k++;
	}
	arr[k] = 0;
	return (arr);
}
