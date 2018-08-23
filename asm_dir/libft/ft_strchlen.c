/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:07:30 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/09 09:30:19 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the number of characters before the first occurrence of a char in a
** string. If char is not found, returns -1.
*/

int	ft_strchlen(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
