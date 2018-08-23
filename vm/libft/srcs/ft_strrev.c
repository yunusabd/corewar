/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:56:43 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/03 22:08:49 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	int		len;
	int		i;
	char	*rev;

	len = ft_strlen(s);
	if (!(rev = (char*)malloc(sizeof(*rev) * len + 1)) || !s)
		return (NULL);
	i = 0;
	len--;
	while (s[i])
	{
		rev[i] = s[len];
		i++;
		len--;
	}
	rev[i] = '\0';
	return (rev);
}
