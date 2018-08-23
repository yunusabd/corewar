/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

static void	as_print_msg(int t, t_list_error *e, t_list_label **l, t_flags *f)
{
	int			lnr;
	int			cnr;
	static int	w = 0;

	lnr = e->line_nr;
	cnr = e->column_nr;
	if (t == 1 || t == 6 || t == 7)
		as_err1(e->message, lnr, e->line, cnr);
	if (t == 4)
		as_label_error(as_label_sug(e->message, *l), lnr, e->line, cnr + 1);
	if (t == 5)
		as_err1(e->message, lnr, NULL, 0);
	if (t == 2 && !(f->v))
		w = as_war1(e->message, lnr, e->line, cnr);
	if (t == 9 && (w || f->v || (e->message)[1] == 'a'))
		w = as_write_err(e->message, lnr, cnr, 2);
	if (t == 10 && f->v && !(f->v))
		as_war1(e->message, lnr, e->line, cnr);
	if (t == 3)
		as_note_type(lnr, cnr, e->message);
	if (t == 6)
		as_note_cmd(lnr, e->line, cnr);
	if (t == 7)
		as_note_reg(lnr, cnr);
}

static void	as_print_error_loop(t_list_error *e, t_list_label **l, t_flags *f)
{
	while (e)
	{
		as_print_msg(e->type, e, l, f);
		e = e->next;
	}
}

static void	as_error_count(t_list_error *error, int *ec, int *wc, t_flags *f)
{
	int	t;

	while (error)
	{
		t = error->type;
		(*ec) = (t == 1 || t == 4 || t == 5 || t == 6 || t == 7)
		? (*ec + 1) : (*ec);
		if ((t == 2 && !(f->v)) || (t == 10 && !(f->v) && f->v))
			(*wc)++;
		error = error->next;
	}
}

static void	as_print_error_num(int error_count, int warning_count)
{
	if (!warning_count && !error_count)
		return ;
	ft_putstr_fd("\n", 2);
	if (error_count)
	{
		as_errnbr(error_count);
		ft_putstr_fd(" error", 2);
	}
	if (error_count > 1)
		ft_putstr_fd("s", 2);
	if (error_count && warning_count)
		ft_putstr_fd(" and ", 2);
	if (warning_count)
	{
		as_errnbr(warning_count);
		ft_putstr_fd(" warning", 2);
	}
	if (warning_count > 1)
		ft_putstr_fd("s", 2);
	ft_putstr_fd(" generated.\n", 2);
}

int			as_print_error(t_list_error **err, t_list_label **label, t_flags *f)
{
	int	error_count;
	int	warning_count;

	error_count = 0;
	warning_count = 0;
	as_error_count(*err, &error_count, &warning_count, f);
	as_print_error_loop(*err, label, f);
	as_print_error_num(error_count, warning_count);
	if (error_count)
		as_free_error(err);
	return (error_count);
}
