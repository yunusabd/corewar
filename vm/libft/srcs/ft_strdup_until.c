/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:13:16 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 20:11:37 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_until(const char *s, const char *end)
{
	size_t		i;
	char		*new;

	i = 0;
	while (s[i] && &s[i] != end)
		i++;
	if (!(new = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (s[i] && &s[i] != end)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
