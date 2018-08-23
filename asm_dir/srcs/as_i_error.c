/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_i_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/20 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

static int	as_i_chars(char *line, int i, int j, t_list_error **error)
{
	char	c;

	c = line[i];
	line[i] = '\0';
	if (ft_hasnondigits(line + j))
	{
		line[i] = c;
		if (!as_add_error(error, ERROR11, line, j + 1))
			return (0);
		return (-1);
	}
	line[i] = c;
	return (1);
}

static int	as_i_length(char *line, int i, int j, t_list_error **error)
{
	char	c;
	int		warning;

	warning = 0;
	c = line[i];
	line[i] = '\0';
	if (I_LENGTH_CHECK && ft_atoi(line + j) > IDX_MOD)
		warning = 1;
	line[i] = c;
	if (warning && !as_add_warning(error, WARNING12, line, j + 1))
		return (0);
	return (1);
}

static int	as_i_value(char *line, int *i, int j, t_list_error **error)
{
	int	ret;

	ret = 0;
	as_skip_rev_space(line, i);
	if (!(ret = as_i_chars(line, *i, j, error)))
		return (0);
	if (ret != -1 && !(ret = as_i_length(line, *i, j, error)))
		return (0);
	return (ret == -1) ? (-1) : (1);
}

int			as_i_e(char *line, int *i, t_list_error **error, int *params_size)
{
	int j;
	int ret;
	int	pos;

	ret = 0;
	pos = as_get_pos(0, 0);
	j = as_j(0, 0) + 1;
	if (!(ret = as_i_value(line, i, j - 1, error)))
		return (0);
	if (ret != -1 && (-1 == (ret = as_type_e(pos, as_k(0), 8))))
	{
		if (!as_add_error(error, ERROR15, line, j))
			return (0);
		if (!as_ant(error, as_get_err_par(pos, as_k(0)), line, j))
			return (0);
	}
	if (ret != -1)
		*params_size = *params_size + IND_SIZE;
	return (1);
}
