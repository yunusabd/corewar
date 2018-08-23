/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_parse3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:31:23 by jszabo            #+#    #+#             */
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

int			as_pp_loop(char *l, t_list_label **lab, t_list_error **err, int *ps)
{
	int ret;
	int i;
	int	p;

	p = as_get_pos(0, 0);
	ret = 0;
	i = as_i(0, 0);
	if (!as_bw_params(&i, l, err) || ((l[as_j(0, 0)] == 'r')
	&& !as_r_e(l, &i, err, ps)) || (as_d(l) && !(ret = as_dlab_e(l, lab, err))))
		return (0);
	if (as_d(l) == 2 && ret != -1 && ((p > 7 && p < 12) || p == 13 || p == 14))
		*ps = *ps + IND_SIZE;
	*ps = (as_d(l) == 2 && ret != -1
	&& !((p > 7 && p < 12) || p == 13 || p == 14)) ? (*ps + DIR_SIZE) : (*ps);
	if ((as_d(l) == 1 && ret == -1 && !as_d_e(l, &i, err, ps))
	|| (as_ind(l) == 2 && (((-1 == as_type_e(p, as_k(0), 8))
	&& (!as_add_error(err, ERROR15, l, as_j(0, 0) + 1)
	|| !as_ant(err, as_get_err_par(p, as_k(0)), l, as_j(0, 0) + 1)))
	|| !as_lab_e(as_j(0, 0) + 1, l, err, lab))))
		return (0);
	*ps = (as_ind(l) == 2) ? (*ps + 2) : (*ps);
	if ((as_ind(l) == 1 && !as_i_e(l, &i, err, ps))
	|| (!as_check_valid_params(err, l) || !as_skip_to_next_param(l, err, &i)))
		return (0);
	return (as_i(i, 1) + 1);
}

int			as_parse_loop(
char *line, t_list_error **error, t_list_label **label, int *bc)
{
	static int	sec = 0;
	static int	suc = 0;
	int			save;

	if (as_line_nr(0) >= MAX_LINE_NUM)
		return (as_err1(ERROR37, 0, NULL, 0) - 1);
	if (!line[0] && !suc)
		as_empty_line_check(error, 1, line);
	else if (!as_empty_line_check(error, 0, line))
		return (as_free_line(line));
	as_endcomment(line, 0);
	if (line[0] && line[0] != COMMENT_CHAR)
	{
		save = sec;
		if ((sec == 2 && !as_p_ops(line, error, label, bc))
		|| (sec == 1 && !as_pcomment(line, &sec, error, bc))
		|| (sec == 0 && !as_pname(line, &sec, error, bc)))
			return (as_free_line(line));
		if (sec > save)
			suc = 0;
		else if (sec == 0 || sec == 1)
			suc = 1;
	}
	return (sec + 1);
}
