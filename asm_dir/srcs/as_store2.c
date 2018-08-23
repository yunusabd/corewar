/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_store2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:31:23 by jszabo            #+#    #+#             */
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

static int	as_sr(t_list_byte **code, t_list_byte **encoding, char *line)
{
	if (as_enc(encoding, -1)
	&& !(as_add_byte(code, (unsigned char)ft_atoi(line + as_j(0, 0) + 1), 8)))
		return (0);
	return (1);
}

static void	as_bw_sparams(char *line, int *i)
{
	as_skip_space(line, i);
	as_j(1, *i);
	as_skip_to_sep(line, i);
	as_k(2);
}

int			as_get_par(char *l, t_list_label **lab, t_list_byte **c, t_flags *f)
{
	int			i;
	t_list_byte	*encoding;
	t_list_byte	*op_pos;
	int			byte_pos;

	op_pos = *c;
	byte_pos = as_code_size(*c) - 1;
	if (!as_gparams_init(&i, c, l, &encoding))
		return (0);
	while (l[i])
	{
		as_bw_sparams(l, &i);
		if ((((l[as_j(0, 0)] == 'r') && !as_sr(c, &encoding, l)))
		|| ((as_d(l) == 2 && as_enc(&encoding, 2)
		&& !as_dlabel(l, lab, byte_pos, c))
		|| (as_d(l) == 1 && as_enc(&encoding, 2) && !as_sd(l, c))
		|| (as_ind(l) == 2 && as_enc(&encoding, 5)
		&& !as_ilabel(l, lab, byte_pos, c))
		|| (as_ind(l) == 1 && as_enc(&encoding, 5) && !as_si(l, c))))
			return (0);
		as_skip_space(l, &i);
		if (l[i])
			i++;
	}
	return (as_pa(f, c, encoding, &op_pos));
}

int			as_get_command(char *line, int i, t_list_byte **code, t_flags *f)
{
	int	j;
	int	k;

	k = 0;
	j = as_get_op_pos(line, i);
	if (j < 0)
		return (j);
	if (!(as_add_byte(code, (unsigned char)g_op_tab[j].opcode, 1)))
		return (0);
	if (f->a)
	{
		ft_printf(GREEN "operation %s (1 byte):  " RESET, g_op_tab[j].opname);
		as_write_byte(*code);
		ft_putchar('\n');
	}
	return (1);
}

int			as_store_magic(t_list_byte **code)
{
	int			magic;
	int			i;

	i = 4;
	magic = COREWAR_EXEC_MAGIC;
	while (i)
	{
		if (!(as_add_byte(code, magic % 256, 0)))
			return (0);
		magic = (magic - (magic % (256))) / (256);
		i--;
	}
	as_rlist(code);
	return (1);
}
