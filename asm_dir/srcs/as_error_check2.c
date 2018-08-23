/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_check2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/03 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

static int	as_ccheck_init2(char *line, int *i, int *j)
{
	as_endcomment(line, 1);
	*i = 0;
	if (!as_skip_name(line, i, j))
	{
		as_err1(ERROR17, as_line_nr(0), line, *j + 1);
		return (0);
	}
	return (1);
}

static int	as_cnspec(char *line, t_list_error **error, int a)
{
	int i;

	i = 0;
	as_skip_space(line, &i);
	if (i > 0 && a == 0 && !as_add_warning2(error, WARNING17, line, i))
		return (0);
	if (i > 0 && a == 1 && !as_add_warning2(error, WARNING18, line, i))
		return (0);
	if (a == 0 && ft_strncmp(line + i, NAME_CMD_STRING,
	ft_strlen(NAME_CMD_STRING)))
	{
		if (!as_add_error(error, ERROR1, line, 1))
			return (0);
		return (2);
	}
	if (a == 1 && !(!(ft_strncmp(line + i, COMMENT_CMD_STRING,
	ft_strlen(COMMENT_CMD_STRING)))))
	{
		if (!as_add_error(error, ERROR7, line, 1))
			return (0);
		return (2);
	}
	return (1);
}

int			as_comment_check(int *i, char *line, t_list_error **error, int *bc)
{
	int			j;
	static int	comment = 0;
	static int	length = 0;
	int			ret;

	if (comment && ((ret = as_ccheck_init2(line, i, &j)) != 1))
		return (ret);
	length = (comment) ? length + (*i) - j + 1 : length;
	if (!comment)
	{
		as_ccheck_init(bc, i, &j, line);
		if ((ret = as_cnspec(line, error, 1)) != 1)
			return (ret);
		if (((j == *i && !as_add_warning(error, WARNING4, line, j + 1)))
		|| !as_set_nline_c(i, error, line, &comment))
			return (0);
		if ((ret = as_ccheck1(line, i, &j, error)) != 1)
			return (ret);
		length = (*i) - j;
		if (((*i) - j) && line[*i] == '"')
			return (as_clength_e(length, error, line, i));
	}
	else
		return (as_c_end(length, error, line, i));
	return (1);
}

int			as_name_check(int *i, char *line, t_list_error **error, int *bc)
{
	int			j;
	static int	name = 0;
	static int	length = 0;
	int			ret;

	if (name && ((ret = as_ccheck_init2(line, i, &j)) != 1))
		return (ret);
	length = (name) ? length + (*i) - j + 1 : length;
	if (!name)
	{
		as_ncheck_init(bc, i, &j, line);
		if ((ret = as_cnspec(line, error, 0)) != 1)
			return (ret);
		if (((j == *i && !as_add_warning(error, WARNING1, line, j + 1)))
		|| !as_set_nline_n(i, error, line, &name))
			return (0);
		if ((ret = as_ncheck1(line, i, &j, error)) != 1)
			return (ret);
		length = (*i) - j;
		if (((*i) - j) && line[*i] == '"')
			return (as_nlength_e(length, error, line, i));
	}
	else
		return (as_n_end(length, error, line, i));
	return (1);
}
