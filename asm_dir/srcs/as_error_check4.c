/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_check4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:31:23 by jszabo            #+#    #+#             */
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

int	as_set_nline_c(int *i, t_list_error **error, char *line, int *comment)
{
	int	ret;

	ret = as_check_quot(i, error, line, ERROR5);
	if (!ret)
		return (0);
	else if (ret == 2)
		*comment = 1;
	return (1);
}

int	as_set_nline_n(int *i, t_list_error **error, char *line, int *comment)
{
	int	ret;

	ret = as_check_quot(i, error, line, ERROR2);
	if (!ret)
		return (0);
	else if (ret == 2)
		*comment = 1;
	return (1);
}

int	as_ccheck1(char *line, int *i, int *j, t_list_error **error)
{
	if (!as_skip_name(line, i, j))
	{
		as_err1(ERROR17, as_line_nr(0), line, *j + 1);
		return (0);
	}
	if ((!((*i) - *j) && line[*i] == '"'
	&& !as_add_warning(error, WARNING5, line, (*i) + 1)))
		return (0);
	if (!((*i) - *j) && line[*i] == '"')
		return (2);
	return (1);
}

int	as_ncheck1(char *line, int *i, int *j, t_list_error **error)
{
	if (!as_skip_name(line, i, j))
	{
		as_err1(ERROR17, as_line_nr(0), line, *j + 1);
		return (0);
	}
	if ((!((*i) - *j) && line[*i] == '"'
	&& !as_add_warning(error, WARNING19, line, (*i) + 1)))
		return (0);
	if (!((*i) - *j) && line[*i] == '"')
		return (2);
	return (1);
}
