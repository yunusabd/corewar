/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:06:07 by yabdulha          #+#    #+#             */
/*   Updated: 2017/12/04 21:21:01 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(const char **arr)
{
	int i;
	int j;

	i = 0;
	if (arr)
	{
		while (arr[i] != '\0')
		{
			j = 0;
			while (arr[i][j] != '\0')
			{
				ft_putchar(arr[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}
