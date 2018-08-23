/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:00:30 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/18 17:31:18 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_determine_len(int n, int len)
{
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		len++;
	}
	return (len);
}

static	void	ft_num_loop(int len, long long *tmp, char **ans)
{
	while (len > 0)
	{
		(*ans)[len - 1] = ((*tmp) % 10) + '0';
		*tmp = ((*tmp) - ((*tmp) % 10)) / 10;
		len--;
	}
}

char			*ft_ftoa(double n, size_t pr)
{
	int			len;
	char		*ans;
	long long	tmp;
	char		*beg;

	if (!(beg = n < 0 ? ft_longlongtoa((long long)(n - 1e-9)) :
	ft_longlongtoa((long long)(n + 1e-9))))
		return (NULL);
	if (!pr)
		return (beg);
	n = (n < 0) ? -n : n;
	tmp = (ft_round((n - (long long)n) * ft_power(10, (int)pr))) + 1e-9;
	len = ft_strlen(beg) + ft_determine_len(tmp, 0) + 1;
	if (!(ans = (char *)malloc(sizeof(*ans) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	ft_num_loop(len, &tmp, &ans);
	len = ft_strlen(ans);
	ans = ft_strcpy(ans, beg);
	ans[len - pr - 1] = '.';
	free(beg);
	return (ans);
}
