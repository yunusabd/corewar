/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/26 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

static int	as_labend_e(int k, int j, char *line, t_list_error **err)
{
	k = j;
	as_skip_space(line, &j);
	if (j > k && line[j] && line[j] != SEPARATOR_CHAR
	&& !as_add_error(err, ERROR20, line, j))
		return (0);
	return (1);
}

static int	as_lab_e2(t_list_error **err, char *line, int k, int j)
{
	if (!as_add_label_error(err, line, k, j))
		return (0);
	return (as_labend_e(k, j, line, err));
}

int			as_lab_e(int j, char *line, t_list_error **err, t_list_label **lab)
{
	int		k;
	char	c;

	k = j;
	as_skip_space(line, &j);
	if (j > k && line[j] && line[j] != SEPARATOR_CHAR)
		return (as_add_error(err, ERROR23, line, k + 1));
	k = j;
	as_skip_label2(line, &j);
	if (!(j - k))
	{
		as_skip_space(line, &j);
		if (!line[j] || line[j] == SEPARATOR_CHAR)
			return (as_add_error(err, ERROR22, line, j));
	}
	as_lab_skip(line, &j, &c);
	if (!as_cmp_label(*lab, line, k))
	{
		line[j] = c;
		return (as_lab_e2(err, line, k, j));
	}
	line[j] = c;
	return (as_labend_e(k, j, line, err));
}

int			as_dlab_e(char *line, t_list_label **label, t_list_error **error)
{
	int	j;
	int pos;

	j = as_j(0, 0);
	pos = as_get_pos(0, 0);
	if (line[j + 1] == LABEL_CHAR)
	{
		if ((-1 == as_type_e(pos, as_k(0), 4))
		&& (!as_add_error(error, ERROR15, line, j + 1)
		|| !as_ant(error, as_get_err_par(pos, as_k(0)), line, j)))
			return (0);
		return (as_lab_e(j + 2, line, error, label));
	}
	return (-1);
}
