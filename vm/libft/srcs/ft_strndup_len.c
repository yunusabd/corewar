/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:35:28 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 20:36:00 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies n chars from s1, without checking if it exists or not.
**	Use with caution!
*/

char	*ft_strndup_len(const char *s1, size_t n)
{
	char		*cpy;
	size_t		i;

	i = 0;
	if (!(cpy = (char*)malloc(sizeof(*cpy) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
