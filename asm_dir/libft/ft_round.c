/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:10:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/14 13:29:56 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Takes a double, and rounds it up or down depending on the value after the
** dot.
*/

double	ft_round(double n)
{
	return (((n - ((long long)(n + 1e-9))) * 10) > 5) ? n + 1 : n;
}
