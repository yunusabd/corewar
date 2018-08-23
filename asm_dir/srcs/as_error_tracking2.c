/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_tracking2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/03 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include <fcntl.h>

int	as_i(int value, int a)
{
	static int	i = 0;

	if (a)
		i = value;
	return (i);
}

int	as_endcomment(char *line, int a)
{
	static int	endcom = 0;
	static int	pos = 0;
	int			i;
	static char	c = ';';

	i = 0;
	if (a == 1 && endcom)
	{
		endcom = 0;
		line[pos] = c;
		return (endcom);
	}
	while (!a && line[i])
	{
		if (line[i] == ';' || line[i] == COMMENT_CHAR)
		{
			c = line[i];
			line[i] = '\0';
			endcom = 1;
			pos = i;
			return (endcom);
		}
		i++;
	}
	return (endcom);
}

int	as_length_e(int a)
{
	static int	error = 0;

	if (!a)
		error = 0;
	else if (a == 1)
		error = 1;
	return (error);
}
