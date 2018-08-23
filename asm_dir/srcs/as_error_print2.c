/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_print2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/17 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

int	as_malloc_error1(t_list_error **error, int a)
{
	ft_putstr_fd(BOLDYELLOW "system error:" RESET, 2);
	ft_putstr_fd(BOLDWHITE " malloc failure" RESET, 2);
	if (a == 1)
		ft_putstr_fd(WHITE " (as_add_error)\n" RESET, 2);
	else if (a == 2)
		ft_putstr_fd(WHITE " (as_add_warning)\n" RESET, 2);
	else if (a == 3)
		ft_putstr_fd(WHITE " (as_ant)\n" RESET, 2);
	else if (a == 4)
		ft_putstr_fd(WHITE " (as_add_label_error)\n" RESET, 2);
	else if (a == 5)
		ft_putstr_fd(WHITE " (as_add_error_noline)\n" RESET, 2);
	else if (a == 6)
		ft_putstr_fd(WHITE " (as_add_note_cmd)\n" RESET, 2);
	else if (a == 7)
		ft_putstr_fd(WHITE " (as_add_note_reg)\n" RESET, 2);
	else if (a == 8)
		ft_putstr_fd(WHITE " (as_param_error)\n" RESET, 2);
	else if (a == 9)
		ft_putstr_fd(WHITE " (as_add_note)\n" RESET, 2);
	else if (a == 10)
		ft_putstr_fd(WHITE " (as_add_warning2)\n" RESET, 2);
	as_free_error(error);
	return (0);
}

int	as_err1(char *message, int line_nr, char *line, int column_nr)
{
	as_write_err(message, line_nr, column_nr, 1);
	if (column_nr)
	{
		as_write_err_line(line, column_nr);
		as_write_err_sign(line, column_nr);
	}
	return (1);
}

int	as_err2(char *message, char *filename)
{
	ft_putstr_fd(BOLDYELLOW "file error: " RESET, 2);
	ft_putstr_fd(BOLDWHITE, 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	as_err3(char *message)
{
	ft_putstr_fd(BOLDGREEN "usage: " RESET, 2);
	ft_putstr_fd(WHITE, 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(RESET, 2);
	return (0);
}

int	as_war1(char *message, int line_nr, char *line, int column_nr)
{
	as_write_err(message, line_nr, column_nr, 0);
	as_write_err_line(line, column_nr);
	as_write_err_sign(line, column_nr);
	return (1);
}
