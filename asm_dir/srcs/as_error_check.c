/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

int	as_check_enough_params(t_list_error **error, char *line, int i)
{
	int		pos;
	int		k;
	char	*msg;

	pos = as_get_pos(0, 0);
	k = as_k(0);
	if (!k && !as_add_error(error, ERROR9, line, i + 1))
		return (0);
	if (k && k < g_op_tab[pos].param_count)
	{
		if (!(msg = as_param_error(g_op_tab[pos].param_count, k, error)))
			return (0);
		if (!as_add_error(error, msg, line, i + 1))
			return (as_free_line(msg));
		free(msg);
	}
	return (1);
}

int	as_unexp_check(t_list_error **error, char *line)
{
	if (as_empty_line(3) == 2
	&& (!as_add_error(error, ERROR33, line, ft_strlen(line))
	|| !as_add_note(
	error, " add a new line to the end of the file to silence this warning\n",
	ft_strlen(line))))
		return (as_free_line(line));
	return (1);
}

int	as_empty_line_check(t_list_error **error, int a, char *line)
{
	static int el = 0;

	if (el > 1 && !a && !as_add_warning2(error, WARNING13, line, 1))
		return (0);
	if (a == 2 && el && !as_add_warning2(error, WARNING14, line, 1))
		return (0);
	if (a == 2 && el && !as_add_note(error, NOTE1, 1))
		return (0);
	if (a == 1)
		el++;
	if (a == 0)
		el = 0;
	return (1);
}

int	as_ec(char **line, t_list_error **error, int bc)
{
	int	code_length;

	code_length = bc - PROG_NAME_LENGTH - COMMENT_LENGTH - 16;
	if (code_length <= 0 && !as_add_error_noline(error, ERROR29))
		return (as_free_line(*line));
	if (code_length >= CHAMP_MAX_SIZE && !as_add_error_noline(error, ERROR32))
		return (as_free_line(*line));
	if (code_length <= 0 && !as_add_error_noline(error, ERROR35))
		return (as_free_line(*line));
	free(*line);
	as_reverse_error(error);
	return (1);
}

int	as_lc(char *line, char *filename)
{
	if (!line)
		return (as_err2(ERROR31, filename));
	return (1);
}
