/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/17 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

static int	as_open_close(char *filename, int *fd, int a)
{
	int	l;

	if (a)
	{
		if (close(*fd) < 0)
			return (as_err2(ERROR34, filename));
		return (1);
	}
	l = ft_strlen(filename);
	(*fd) = open(filename, O_RDONLY);
	if ((*fd) < 0)
		return (as_err2(ERROR30, filename));
	if (l <= 2 || (filename[l - 1] != 's' && filename[l - 1] != '.'))
		return (as_err2(ERROR31, filename));
	return (1);
}

static int	as_parse(int fd, t_list_label **label, char *fn, t_flags *flags)
{
	char			*line;
	t_list_error	*error;
	int				bc;

	as_parse_init(&line, &error, &bc);
	while (as_empty_line(get_next_line(fd, &line)) && line)
	{
		if (!(as_parse_loop(line, &error, label, &bc)))
			return (0);
		if (!as_unexp_check(&error, line))
			return (0);
		as_endcomment(line, 1);
		free(line);
		as_line_nr(1);
	}
	if (!as_empty_line_check(&error, 2, line))
		return (as_free_line(line));
	if (!as_lc(line, fn) || !as_ec(&line, &error, bc)
	|| as_print_error(&error, label, flags) || as_free_error(&error))
		return (0);
	return (1);
}

static int	as_flags_init(t_flags **flags, int argc, char **argv, int *pos)
{
	if (!(*flags = (t_flags *)(malloc(sizeof(**flags)))))
		return (as_malloc_error2(NULL, 2));
	(*flags)->v = 0;
	(*flags)->v = 0;
	(*flags)->p = 0;
	(*flags)->a = 0;
	while (*pos < argc && argv[*pos][0] == '-')
		(*pos)++;
	if (argc < 2 || (*pos) == argc)
		return (as_err3(USAGE));
	return (as_flags_loop(flags, argc, argv, pos));
}

int			main(int argc, char **argv)
{
	int				fd;
	t_list_label	*label;
	t_flags			*flags;
	int				pos;

	fd = 0;
	pos = 1;
	label = NULL;
	flags = NULL;
	if (!as_flags_init(&flags, argc, argv, &pos)
	|| !as_open_close(argv[pos], &fd, 0)
	|| !as_parse(fd, &label, argv[pos], flags)
	|| !as_open_close(argv[pos], &fd, 1)
	|| !as_open_close(argv[pos], &fd, 0)
	|| !as_store(fd, &label, argv[pos], flags)
	|| !as_open_close(argv[pos], &fd, 1))
		return (as_free_lab_fla(&label, flags));
	as_free_lab_fla(&label, flags);
	return (0);
}
