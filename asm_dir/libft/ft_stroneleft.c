/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroneleft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:11:28 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/14 14:14:20 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Deletes the first character of a string, by moving all chars to the left
** by one space.
*/

int	ft_stroneleft(char **str)
{
	*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	return (1);
}
