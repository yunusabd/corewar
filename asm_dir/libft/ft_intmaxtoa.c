/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:00:30 by jszabo            #+#    #+#             */
/*   Updated: 2017/12/03 14:53:13 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_determine_len(intmax_t n, int len)
{
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		len++;
	}
	return (len);
}

char			*ft_intmaxtoa(intmax_t n)
{
	int		neg;
	int		len;
	char	*ans;

	len = 0;
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	len = ft_determine_len(n, len);
	len = (n == 0 || neg) ? len + 1 : len;
	if (!(ans = (char *)malloc(sizeof(*ans) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	while (len > 0)
	{
		ans[len - 1] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
		len--;
	}
	ans[0] = (neg) ? '-' : ans[0];
	return (ans);
}
