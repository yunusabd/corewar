/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_tracking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/16 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include <fcntl.h>

int	as_empty_line(int a)
{
	static int	empty = 0;

	if (a <= 2)
		empty = a;
	return (empty);
}

int	as_line_nr(int a)
{
	static int	line_nr = 1;

	if (a)
		line_nr++;
	return (line_nr);
}

int	as_get_pos(unsigned char byte, int a)
{
	static int	pos = 0;

	if (a == 1)
		pos = 0;
	while (a == 1 && byte != g_op_tab[pos].opcode)
		pos++;
	return (pos);
}

int	as_j(int a, int i)
{
	static int j = 0;

	if (a == 1)
		j = i;
	return (j);
}

int	as_k(int a)
{
	static int k = 0;

	if (a == 1)
		k = 0;
	else if (a == 2)
		k++;
	return (k);
}
