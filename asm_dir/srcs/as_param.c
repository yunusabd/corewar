/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:31:23 by jszabo            #+#    #+#             */
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

int			as_bw_params(int *i, char *line, t_list_error **error)
{
	as_j(1, *i);
	as_skip_to_sep(line, i);
	as_k(2);
	if (as_k(0) > g_op_tab[as_get_pos(0, 0)].param_count
	&& !as_add_error(error, ERROR16, line, as_j(0, 0) + 1))
		return (0);
	if (line[*i] == SEPARATOR_CHAR && ft_isspace(line[*i - 1])
	&& !as_add_warning2(error, WARNING8, line, *i))
		return (0);
	return (1);
}

int			as_enc(t_list_byte **enc, int start)
{
	int			k;
	int			pos;
	const int	arr[9] = {64, 16, 4, 128, 32, 8, 192, 48, 12};

	k = as_k(0);
	pos = as_get_pos(0, 0);
	if (k <= g_op_tab[pos].param_count && *enc)
		(*enc)->byte = (*enc)->byte + (unsigned char)(arr[start + k]);
	return (1);
}

int			as_cmp_label(t_list_label *label, char *line, int k)
{
	while (label)
	{
		if (!ft_strcmp(line + k, label->name))
			return (label->pos);
		label = label->next;
	}
	return (0);
}

static int	as_lab_value(char *l, int *i, t_list_error **e, t_list_label **lab)
{
	char c;

	as_del_label_errors(e, l, *i);
	c = l[*i];
	l[*i] = '\0';
	if (as_cmp_label(*lab, l, 0))
	{
		l[*i] = c;
		if (!as_add_error(e, ERROR24, l, 1))
			return (0);
	}
	else if (!as_add_label(lab, l, *i, 0))
	{
		l[*i] = c;
		return (as_free_error(e));
	}
	l[*i] = c;
	(*i)++;
	return (1);
}

int			as_slabel(char *l, int *i, t_list_error **err, t_list_label **label)
{
	if (as_skip_label2(l, i) && l[*i] == LABEL_CHAR && *i <= LABEL_SIZE)
		as_lab_value(l, i, err, label);
	else if ((*i) > LABEL_SIZE)
	{
		if (!as_add_error(err, ERROR10, l, *i + 1))
			return (0);
		(*i)++;
	}
	else
		*i = 0;
	return (1);
}
