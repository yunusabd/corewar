/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_check5.c                                  :+:      :+:    :+:   */
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

int	as_clength_e(int length, t_list_error **error, char *line, int *i)
{
	if (!as_length_e(2) && length > COMMENT_LENGTH)
	{
		as_length_e(1);
		if (!as_add_warning(error, WARNING7, line, (*i) + 2))
			return (0);
	}
	if (line[*i + 1] && !as_add_warning(error, WARNING6, line, (*i) + 1))
		return (0);
	return (2);
}

int	as_nlength_e(int length, t_list_error **error, char *line, int *i)
{
	if (!as_length_e(2) && length > PROG_NAME_LENGTH)
	{
		as_length_e(1);
		if (!as_add_warning(error, WARNING3, line, (*i) + 2))
			return (0);
	}
	if (line[*i + 1] && !as_add_warning(error, WARNING2, line, (*i) + 1))
		return (0);
	return (2);
}

int	as_c_end(int length, t_list_error **error, char *line, int *i)
{
	if (!as_length_e(2) && length > COMMENT_LENGTH)
	{
		as_length_e(1);
		if (!as_add_warning(error, WARNING7, line, (*i) + 2))
			return (0);
	}
	if (line[*i] && line[*i] == '"' && line[*i + 1]
	&& !as_add_warning(error, WARNING6, line, (*i) + 2))
		return (0);
	*i = 0;
	while (line[*i] && line[*i] != '"')
		(*i)++;
	if (line[*i] && line[*i] == '"')
		return (2);
	return (1);
}

int	as_n_end(int length, t_list_error **error, char *line, int *i)
{
	if (!as_length_e(2) && length > PROG_NAME_LENGTH)
	{
		as_length_e(1);
		if (!as_add_warning(error, WARNING3, line, (*i) + 2))
			return (0);
	}
	if (line[*i] && line[*i] == '"' && line[*i + 1]
	&& !as_add_warning(error, WARNING2, line, (*i) + 2))
		return (0);
	*i = 0;
	while (line[*i] && line[*i] != '"')
		(*i)++;
	if (line[*i] && line[*i] == '"')
		return (2);
	return (1);
}
