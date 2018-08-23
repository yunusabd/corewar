/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:14:00 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 20:32:55 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*cpy;
	size_t		i;

	i = 0;
	if (!(cpy = (char*)malloc(sizeof(*cpy) * (n + 1))))
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
