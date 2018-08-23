/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_d_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/25 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

static int	as_d_chars(char *line, int i, int j, t_list_error **error)
{
	char	c;
	int		k;

	k = i;
	while (line[i] != DIRECT_CHAR && !ft_isspace(line[i]))
		i--;
	if (k != i && line[i] != DIRECT_CHAR)
	{
		if (!as_add_error(error, ERROR20, line, k))
			return (0);
		return (-1);
	}
	i = k;
	c = line[i];
	line[i] = '\0';
	if (ft_hasnondigits(line + j + 1))
	{
		line[i] = c;
		if (!as_add_error(error, ERROR11, line, j + 1))
			return (0);
		return (-1);
	}
	line[i] = c;
	return (1);
}

static int	as_d_length(char *line, int i, int j, t_list_error **error)
{
	char c;

	c = line[i];
	line[i] = '\0';
	if (ft_atoll(line + j + 1) > 2147483647
	|| ft_atoll(line + j + 1) < -2147483648
	|| ft_strlen(line + j + 1) > 11)
	{
		line[i] = c;
		if (!as_add_error(error, ERROR26, line, j + 2))
			return (0);
		return (-1);
	}
	line[i] = c;
	return (1);
}

static int	as_d_value(char *line, int *i, int j, t_list_error **error)
{
	int ret;

	ret = 0;
	as_skip_rev_space(line, i);
	if (!(ret = as_d_chars(line, *i, j, error)))
		return (0);
	if (D_LENGTH_CHECK && ret != -1
	&& !(ret = as_d_length(line, *i, j, error)))
		return (0);
	return (ret == -1) ? (-1) : (1);
}

static int	as_d_val_type(char *line, int *i, int *ret, t_list_error **error)
{
	int	j;
	int	pos;

	j = as_j(0, 0);
	pos = as_get_pos(0, 0);
	if (!(*ret = as_d_value(line, i, j, error)))
		return (0);
	if ((-1 == (*ret = as_type_e(pos, as_k(0), 4))) &&
	(!as_add_error(error, ERROR15, line, j)
	|| !as_ant(error, as_get_err_par(pos, as_k(0)), line, j)))
		return (0);
	return (1);
}

int			as_d_e(char *line, int *i, t_list_error **error, int *ps)
{
	int j;
	int ret;
	int	pos;

	ret = 0;
	pos = as_get_pos(0, 0);
	j = as_j(0, 0) + 1;
	if (!line[j] || ft_isspace(line[j]) || line[j] == SEPARATOR_CHAR)
	{
		ret = -1;
		if (!as_add_error(error, ERROR25, line, j + 1))
			return (0);
	}
	else if (line[j] && !as_d_val_type(line, i, &ret, error))
		return (0);
	*ps = (ret != -1) ? (*ps + DIR_SIZE) : (*ps);
	*ps = (ret != -1 &&
	(pos == 10 || pos == 8 || pos == 9 || pos == 11
	|| pos == 13 || pos == 14))
	? (*ps - DIR_SIZE + IND_SIZE) : (*ps);
	return (1);
}
