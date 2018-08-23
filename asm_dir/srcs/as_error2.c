/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <unistd.h>

int		as_add_note_cmd(t_list_error **error, char *m, char *line, int cnr)
{
	t_list_error	*new;

	as_endcomment(line, 1);
	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->line = ft_strnew(ft_strlen(line)))
	|| !(new->message = ft_strnew(ft_strlen(m))))
		return (as_malloc_error1(error, 6));
	ft_strcpy(new->line, line);
	ft_strcpy(new->message, m);
	new->type = 6;
	new->line_nr = as_line_nr(0);
	new->column_nr = cnr;
	new->next = *error;
	*error = new;
	as_endcomment(line, 0);
	return (1);
}

int		as_add_note_reg(t_list_error **error, char *m, char *line, int cnr)
{
	t_list_error	*new;

	as_endcomment(line, 1);
	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->line = ft_strnew(ft_strlen(line)))
	|| !(new->message = ft_strnew(ft_strlen(m))))
		return (as_malloc_error1(error, 7));
	ft_strcpy(new->line, line);
	ft_strcpy(new->message, m);
	new->type = 7;
	new->line_nr = as_line_nr(0);
	new->column_nr = cnr;
	new->next = *error;
	*error = new;
	as_endcomment(line, 0);
	return (1);
}

int		as_add_error_noline(t_list_error **error, char *message)
{
	t_list_error	*new;

	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->message = ft_strnew(ft_strlen(message))))
		return (as_malloc_error1(error, 5));
	ft_strcpy(new->message, message);
	new->line = NULL;
	new->type = 5;
	new->line_nr = 0;
	new->column_nr = 0;
	new->next = *error;
	*error = new;
	return (1);
}

int		as_add_label_error(t_list_error **error, char *line, int cnr, int j)
{
	t_list_error	*new;
	char			c;

	as_endcomment(line, 1);
	c = line[j];
	if (!(new = (t_list_error *)malloc(sizeof(*new)))
	|| !(new->line = ft_strnew(ft_strlen(line))))
		return (as_malloc_error1(error, 4));
	ft_strcpy(new->line, line);
	line[j] = '\0';
	if (!(new->message = ft_strnew(ft_strlen(line + cnr))))
		return (as_malloc_error1(error, 4));
	ft_strcpy(new->message, line + cnr);
	line[j] = c;
	new->type = 4;
	new->line_nr = as_line_nr(0);
	new->column_nr = cnr;
	new->next = *error;
	*error = new;
	as_endcomment(line, 0);
	return (1);
}

char	*as_get_err_par(int co, int k)
{
	if (g_op_tab[co].param_type[k - 1] == T_DIR)
		return (BOLDWHITE " direct" RESET);
	else if (g_op_tab[co].param_type[k - 1] == T_DIR + T_IND)
		return (BOLDWHITE " direct or indirect" RESET);
	else if (g_op_tab[co].param_type[k - 1] == T_REG)
		return (BOLDWHITE " register" RESET);
	else if (g_op_tab[co].param_type[k - 1] == T_IND + T_REG)
		return (BOLDWHITE " indirect or register" RESET);
	else if (g_op_tab[co].param_type[k - 1] == T_DIR + T_REG)
		return (BOLDWHITE " direct or register" RESET);
	return (NULL);
}
