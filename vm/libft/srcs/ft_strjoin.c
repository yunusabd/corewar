/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:32:17 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/05 20:56:38 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		len1;
	int		len;

	if (!(s1 && s2))
		return (NULL);
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	i = 0;
	if (!(new = (char*)malloc(sizeof(*new) * len + 1)))
		return (NULL);
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (len1 <= len)
	{
		new[len1] = s2[i];
		i++;
		len1++;
	}
	return (new);
}
