/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:26:38 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/01 17:31:43 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	i = 0;
	while (len > 0)
	{
		new[i] = s[start];
		i++;
		start++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
