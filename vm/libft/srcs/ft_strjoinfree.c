/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:32:17 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/01 15:27:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_str(char *s1, char *s2, int del)
{
	if (del == 1)
		free(s1);
	else if (del == 2)
		free(s2);
	else
	{
		free(s1);
		free(s2);
	}
}

char			*ft_strjoinfree(char *s1, char *s2, int del)
{
	char	*new;
	int		i;
	int		len1;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < len1)
			new[i] = s1[i];
		if (i < (len - len1))
			new[i + len1] = s2[i];
		i++;
	}
	free_str(s1, s2, del);
	return (new);
}
