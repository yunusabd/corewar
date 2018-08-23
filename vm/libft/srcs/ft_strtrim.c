/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:53:29 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/01 17:38:22 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	j = len;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len >= i)
		len--;
	if (j == len && i == 0)
		return (ft_strdup(s));
	else
		return (ft_strsub(s, i, (len - i + 1)));
}
