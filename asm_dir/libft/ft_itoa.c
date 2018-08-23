/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:00:30 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 17:09:53 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*ft_special(void)
{
	char	*ans;

	ans = ft_itoa(-2147483647);
	ans[10] = 8 + '0';
	return (ans);
}

static	int		ft_determine_len(int n, int len)
{
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*ans;

	len = 0;
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	if (n == -2147483648)
		return (ft_special());
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
