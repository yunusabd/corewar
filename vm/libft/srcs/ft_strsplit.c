/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:10:01 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/05 21:18:13 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_allocate_wordcount(char const *s, char **arr, char c)
{
	int		wordcount;
	int		i;
	int		len;

	i = 0;
	wordcount = 0;
	len = ft_strlen(s);
	while (i < len && s[i] != '\0')
	{
		if (s[i] != c)
		{
			wordcount++;
			while (s[i] != c && i < len && s[i] != '\0')
				i++;
		}
		i++;
	}
	if (!(arr = (char**)malloc(sizeof(*arr) * (wordcount + 1))))
		return (NULL);
	return (arr);
}

static char	**ft_putwords(char const *s, char c, char **arr)
{
	int		tmp;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (i < len && s[i] != '\0')
	{
		if (s[i] != c && i < len && s[i] != '\0')
		{
			tmp = i;
			while (s[i] != c && i < len && s[i] != '\0')
				i++;
			if (!(arr[j] = ft_strndup((&s[tmp]), (i - tmp))))
				return (NULL);
			j++;
		}
		while (s[i] == c && i < len && s[i] != '\0')
			i++;
	}
	arr[j] = 0;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = NULL;
	if (!(arr = ft_allocate_wordcount(s, arr, c)))
		return (NULL);
	if (!(ft_putwords(s, c, arr)))
		return (NULL);
	return (arr);
}
