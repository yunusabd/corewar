/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:21:10 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/02 12:16:09 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *new;

	new = (char *)malloc(sizeof(*new) * ft_strlen(s1) + 1);
	if (!new)
		return (NULL);
	new = ft_strcpy(new, s1);
	return (new);
}
