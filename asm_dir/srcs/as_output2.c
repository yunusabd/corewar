/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_output2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/28 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

static void		as_putnspace(int n)
{
	while (n)
	{
		ft_putchar(' ');
		n--;
	}
}

static void		as_print_a3(t_list_byte **n, t_list_byte **o, int *m, int i)
{
	*o = *n;
	while (i < *m)
	{
		as_write_byte(*o);
		if ((*o)->next)
			*n = *o;
		*o = (*o)->next;
		i++;
	}
	*o = *n;
	ft_putchar('\n');
}

static void		as_print_a2(int n, t_list_byte **op_pos, int *m, char *str)
{
	t_list_byte	*node;
	int			i;
	int			j;
	int			p;

	i = 0;
	j = 4;
	p = as_get_pos(0, 0);
	if (((p == 8 || p == 9 || p == 10 || p == 11 || p == 13 || p == 14)
	&& n == 3) || (p == 5 && n == 9))
		j = 2;
	node = *op_pos;
	while (*op_pos && (*op_pos)->type == n && *m < j)
	{
		*op_pos = (*op_pos)->next;
		(*m)++;
	}
	if (*m == 1)
		return ;
	ft_printf(MAGENTA "%s" RESET, str);
	as_putnspace(ft_strlen(g_op_tab[as_get_pos(0, 0)].opname));
	if (n == 3)
		ft_printf("  ");
	ft_printf(MAGENTA "   (%d bytes): " RESET, *m);
	as_print_a3(&node, op_pos, m, i);
}

static void		as_print_a1(int n, t_list_byte *code)
{
	if (n == 1)
		ft_printf(CYAN "encoding" RESET);
	if (n == 2)
		ft_printf(MAGENTA "register" RESET);
	as_putnspace(ft_strlen(g_op_tab[as_get_pos(0, 0)].opname));
	if (n == 1)
		ft_printf(CYAN "   (1 byte):  " RESET);
	if (n == 2)
		ft_printf(MAGENTA "   (1 byte):  " RESET);
	as_write_byte(code);
	ft_putchar('\n');
}

int				as_pa(t_flags *f, t_list_byte **code,
t_list_byte *encoding, t_list_byte **op_pos)
{
	int			m;

	if (f->a && encoding)
		as_print_a1(1, encoding);
	if (f->a)
	{
		as_rlist(code);
		while (*op_pos)
		{
			m = 0;
			if ((*op_pos)->type == 8)
				as_print_a1(2, *op_pos);
			else if ((*op_pos)->type == 3)
				as_print_a2(3, op_pos, &m, "direct");
			else if ((*op_pos)->type == 9)
				as_print_a2(9, op_pos, &m, "indirect");
			if (*op_pos)
				*op_pos = (*op_pos)->next;
		}
		as_rlist(code);
	}
	return (1);
}
