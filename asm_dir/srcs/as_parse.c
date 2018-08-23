/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/19 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

static int	as_pparams(char *l, t_list_label **lab, t_list_error **err, int *bc)
{
	int	i;
	int	params;
	int	params_size;
	int j;

	params = as_pparams_init(&i, l, &params_size);
	if (params == 2 && !as_add_warning2(err, WARNING11, l, i + 1))
		return (0);
	as_i(i, 1);
	while (l[i] && params)
	{
		if (!as_pp_loop(l, lab, err, &params_size))
			return (0);
		i = as_i(0, 0);
	}
	j = as_j(0, 0);
	while (l[j] && l[j] != SEPARATOR_CHAR)
		j++;
	if (l[j] == SEPARATOR_CHAR && !as_add_error(err, ERROR4, l, j + 1))
		return (0);
	if (!as_check_enough_params(err, l, i))
		return (0);
	*bc = *bc + params_size;
	return (1);
}

static int	as_p_op(char *line, int i, t_list_error **error, int *byte_count)
{
	int	j;
	int k;

	j = as_get_op_pos(line, i);
	k = i + ft_strlen(g_op_tab[j].opname);
	if (j == -1 || (!ft_isspace(line[k]) && line[k]))
		return (!as_add_note_cmd(error, ERROR8, line, i + 1)) ? (0) : (-1);
	(*byte_count)++;
	return (1);
}

int			as_p_ops(char *l, t_list_error **err, t_list_label **label, int *bc)
{
	int	i;
	int	ret;

	i = as_check_spaces_line(l, err);
	if (i == -1 || !as_check_max_length(l, err))
		return (0);
	if (i == 1)
		return (1);
	ret = as_label_list_size(*label);
	if (!as_slabel(l, &i, err, label))
		return (0);
	if (as_label_list_size(*label) > ret)
		(*label)->pos = *bc;
	ret = 0;
	if ((as_skip_space(l, &i) - i) && l[i - 1] != LABEL_CHAR
	&& !l[i] && !as_endcomment(l, 2) && !as_add_warning2(err, WARNING15, l, i))
		return (0);
	if (!l[i])
		return (1);
	if (!(ret = as_p_op(l, i, err, bc)))
		return (0);
	if (ret > -1 && !as_pparams(l, label, err, bc))
		return (0);
	return (1);
}

int			as_pname(char *line, int *section, t_list_error **error, int *bc)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (!(ret = as_name_check(&i, line, error, bc)))
		return (0);
	if (ret == 2)
	{
		(*section)++;
		as_length_e(0);
	}
	return (1);
}

int			as_pcomment(char *line, int *section, t_list_error **error, int *bc)
{
	int	i;
	int ret;

	ret = 0;
	if (!(ret = as_comment_check(&i, line, error, bc)))
		return (0);
	if (ret == 2)
	{
		(*section)++;
		as_length_e(0);
	}
	return (1);
}
