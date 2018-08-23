/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_store3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/27 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

int			as_ssize(t_list_byte **size, t_list_byte *code)
{
	int	s;
	int	i;

	i = 0;
	s = as_code_size(code) - PROG_NAME_LENGTH - COMMENT_LENGTH - 16;
	while (i < 4)
	{
		(*size)->type = 6;
		(*size)->byte = (s >> (8 * i)) & 0xff;
		(*size) = (*size)->next;
		i++;
	}
	return (1);
}

int			as_store_non_zero(int length, char *line, int *i, t_list_byte **c)
{
	static int	l = 0;

	as_endcomment(line, 1);
	while (line[*i] && line[*i] != '"')
	{
		if (l < length && !(as_add_byte(c, line[*i], 5)))
			return (0);
		(*i)++;
		l++;
	}
	if (line[*i] == '"')
	{
		l = 0;
		return (2);
	}
	else if (l < length)
	{
		if (!(as_add_byte(c, '\n', 5)))
			return (0);
		l++;
	}
	return (1);
}

int			as_store_zero(int i, int section, t_list_byte **code)
{
	i = (section) ?
	(COMMENT_LENGTH - (as_code_size(*code) - PROG_NAME_LENGTH) + 16)
	: (PROG_NAME_LENGTH - as_code_size(*code) + 12);
	while (i > 0)
	{
		if (!(as_add_byte(code, 0, 5)))
			return (0);
		i--;
	}
	return (1);
}
