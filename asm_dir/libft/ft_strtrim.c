/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:36:15 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/05 15:01:08 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !(new = (char *)malloc(sizeof(*new) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
	{
		new[j] = s[i];
		i++;
		j++;
	}
	j--;
	while (new[j] == ' ' || new[j] == '\n' || new[j] == '\t')
	{
		new[j] = '\0';
		j--;
	}
	new[j + 1] = '\0';
	return (new);
}
