/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:51:43 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/02 15:51:39 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char *a;

	a = malloc(sizeof(*a) * (len + 1));
	if (!a)
		return (NULL);
	a = ft_strncpy(a, haystack, len);
	if (ft_strstr(a, needle))
		return (ft_strstr(haystack, needle));
	else
		return (NULL);
}
