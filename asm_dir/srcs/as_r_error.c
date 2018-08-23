/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_r_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/06 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

static int	as_r_chars(char *line, int i, int j, t_list_error **error)
{
	char	c;
	int		k;

	k = i;
	while (line[i] != 'r' && !ft_isspace(line[i]))
		i--;
	if (k != i && line[i] != 'r')
	{
		if (!as_add_error(error, ERROR20, line, k))
			return (0);
		return (-1);
	}
	i = k;
	c = line[i];
	line[i] = '\0';
	if (line[j + 1] == '-' || ft_hasnondigits(line + j + 1))
	{
		line[i] = c;
		if (!as_add_error(error, ERROR11, line, j + 1))
			return (0);
		return (-1);
	}
	line[i] = c;
	return (1);
}

static int	as_r_length(char *line, int i, int j, t_list_error **error)
{
	char c;

	c = line[i];
	line[i] = '\0';
	if (ft_atoi(line + j + 1) > REG_NUMBER
	|| ft_strlen(line + j + 1) > (size_t)ft_numlen(REG_NUMBER))
	{
		line[i] = c;
		if (!as_add_note_reg(error, ERROR13, line, j + 2))
			return (0);
		return (-1);
	}
	line[i] = c;
	return (1);
}

static int	as_r_value(char *line, int *i, int j, t_list_error **error)
{
	int ret;

	ret = 0;
	as_skip_rev_space(line, i);
	if (!(ret = as_r_chars(line, *i, j, error)))
		return (0);
	if (ret != -1 && !(ret = as_r_length(line, *i, j, error)))
		return (0);
	return (ret == -1) ? (-1) : (1);
}

int			as_r_e(char *line, int *i, t_list_error **error, int *params_size)
{
	int j;
	int ret;
	int	pos;

	pos = as_get_pos(0, 0);
	ret = 0;
	j = as_j(0, 0) + 1;
	if (!line[j] || ft_isspace(line[j]) || line[j] == SEPARATOR_CHAR)
	{
		ret = -1;
		if (!as_add_error(error, ERROR12, line, j + 1))
			return (0);
	}
	else if (line[j])
	{
		if (!(ret = as_r_value(line, i, j - 1, error))
		|| (((ret = as_type_e(pos, as_k(0), 0)) == -1)
		&& (!as_add_error(error, ERROR15, line, j) ||
		!as_ant(error, as_get_err_par(pos, as_k(0)), line, j))))
			return (0);
	}
	if (ret != -1)
		(*params_size)++;
	return (1);
}
