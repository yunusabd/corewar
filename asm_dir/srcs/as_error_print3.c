/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_print3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

int		as_write_err(char *message, int line_nr, int column_nr, int e)
{
	if (column_nr)
	{
		ft_putstr_fd(BOLDWHITE, 2);
		ft_putstr_fd("\nline ", 2);
		as_errnbr(line_nr);
		ft_putstr_fd(", column ", 2);
		as_errnbr(column_nr);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(RESET, 2);
	}
	if (e == 2)
		ft_putstr_fd(BOLDBLACK "note:" RESET, 2);
	if (e == 1)
		ft_putstr_fd(BOLDRED "error:" RESET, 2);
	else if (e == 0)
		ft_putstr_fd(BOLDMAGENTA "warning:" RESET, 2);
	if (e == 2)
		ft_putstr_fd(WHITE, 2);
	else
		ft_putstr_fd(BOLDWHITE, 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(RESET, 2);
	return (0);
}

int		as_note_type(int line_nr, int column_nr, char *message)
{
	as_write_err(" switch this to a parameter of type", line_nr, column_nr, 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(" to silence this warning\n", 2);
	return (1);
}

int		as_note_label(int line_nr, int column_nr, char *message)
{
	as_write_err(" did you mean '", line_nr, column_nr, 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("'?\n", 2);
	return (1);
}

int		as_note_reg(int line_nr, int column_nr)
{
	as_write_err(" choose a register number that is not higher than ",
	line_nr, column_nr, 2);
	as_errnbr(REG_NUMBER);
	ft_putstr_fd(" to silence this warning\n", 2);
	return (1);
}

int		as_note_cmd(int line_nr, char *line, int column_nr)
{
	int	j;
	int	highest;
	int	pos;
	int	save;

	j = 15;
	highest = 0;
	pos = -1;
	while (j >= 0)
	{
		if ((save = as_cmd_comp(g_op_tab[j].opname, line + column_nr - 1))
		> highest)
		{
			pos = j;
			highest = save;
		}
		j--;
	}
	if (highest > 1)
	{
		as_write_err(" did you mean '", line_nr, column_nr, 2);
		ft_putstr_fd(g_op_tab[pos].opname, 2);
		ft_putstr_fd("'?\n", 2);
	}
	return (1);
}
