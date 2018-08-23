/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/17 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

int	as_add_error(t_list_error **error, char *message, char *line, int column_nr)
{
	t_list_error	*new;

	as_endcomment(line, 1);
	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->line = ft_strnew(ft_strlen(line)))
	|| !(new->message = ft_strnew(ft_strlen(message))))
		return (as_malloc_error1(error, 1));
	ft_strcpy(new->line, line);
	ft_strcpy(new->message, message);
	new->type = 1;
	new->line_nr = as_line_nr(0);
	new->column_nr = column_nr;
	new->next = *error;
	*error = new;
	as_endcomment(line, 0);
	return (1);
}

int	as_add_warning(t_list_error **error, char *message, char *line, int cnr)
{
	t_list_error	*new;

	as_endcomment(line, 1);
	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->line = ft_strnew(ft_strlen(line)))
	|| !(new->message = ft_strnew(ft_strlen(message))))
		return (as_malloc_error1(error, 2));
	ft_strcpy(new->line, line);
	ft_strcpy(new->message, message);
	new->type = 2;
	new->line_nr = as_line_nr(0);
	new->column_nr = cnr;
	new->next = *error;
	*error = new;
	as_endcomment(line, 0);
	return (1);
}

int	as_add_warning2(t_list_error **error, char *message, char *line, int cnr)
{
	t_list_error	*new;

	as_endcomment(line, 1);
	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->line = ft_strnew(ft_strlen(line)))
	|| !(new->message = ft_strnew(ft_strlen(message))))
		return (as_malloc_error1(error, 10));
	ft_strcpy(new->line, line);
	ft_strcpy(new->message, message);
	new->type = 10;
	new->line_nr = as_line_nr(0);
	new->column_nr = cnr;
	new->next = *error;
	*error = new;
	as_endcomment(line, 0);
	return (1);
}

int	as_add_note(t_list_error **error, char *message, int cnr)
{
	t_list_error	*new;

	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->message = ft_strnew(ft_strlen(message))))
		return (as_malloc_error1(error, 9));
	ft_strcpy(new->message, message);
	new->line = NULL;
	new->type = 9;
	new->line_nr = as_line_nr(0);
	new->column_nr = cnr;
	new->next = *error;
	*error = new;
	return (1);
}

int	as_ant(t_list_error **error, char *message, char *line, int cnr)
{
	t_list_error	*new;

	as_endcomment(line, 1);
	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->line = ft_strnew(ft_strlen(line)))
	|| !(new->message = ft_strnew(ft_strlen(message))))
		return (as_malloc_error1(error, 3));
	ft_strcpy(new->line, line);
	ft_strcpy(new->message, message);
	new->type = 3;
	new->line_nr = as_line_nr(0);
	new->column_nr = cnr;
	new->next = *error;
	*error = new;
	as_endcomment(line, 0);
	return (1);
}
