/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/12 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

static int	as_store_end(t_list_byte **s, t_list_byte **code, int p, char *fn)
{
	if (!as_ssize(s, *code) || !as_rlist(code)
	|| (p && !as_plist(*code)) || !as_wfile(code, fn) || !as_free(code))
		return (0);
	return (1);
}

static int	as_scom(char *l, t_list_byte **c, t_list_label **la, t_flags *f)
{
	int				i;
	int				j;

	i = 0;
	as_skip_label2(l, &i);
	i = (l[i] == LABEL_CHAR) ? (i + 1) : (0);
	as_skip_space(l, &i);
	if (!l[i])
		return (1);
	j = as_get_command(l, i, c, f);
	if (!j)
		return (0);
	if (j != -1 && !as_get_par(l, la, c, f))
		return (0);
	return (1);
}

static void	as_store_nc_suc(int *suc, int *i, int *length, int *sec)
{
	if (*suc)
	{
		*i = 0;
		*length = (*sec) ? COMMENT_LENGTH : PROG_NAME_LENGTH;
	}
	*suc = 1;
}

static int	as_store_nc(char *line, int *sec, t_list_byte **c, t_list_byte **s)
{
	int			i;
	int			length;
	int			ret;
	static int	suc = 0;

	ret = 0;
	if (!suc)
	{
		if (!line[0])
			return (1);
		as_store_name_comment_init(line, &i, *sec, &length);
	}
	as_store_nc_suc(&suc, &i, &length, sec);
	if (!(ret = as_store_non_zero(length, line, &i, c)))
		return (0);
	if (ret == 2)
	{
		if (!as_store_zero(i, *sec, c))
			return (0);
		if (!(*sec))
			*s = *c;
		suc = 0;
		(*sec)++;
	}
	return (1);
}

int			as_store(int fd, t_list_label **label, char *filename, t_flags *f)
{
	char			*line;
	int				sec;
	t_list_byte		*code;
	t_list_byte		*size;

	if (!as_store_init(&line, &code, &size, &sec))
		return (0);
	while (get_next_line(fd, &line))
	{
		as_endcomment(line, 0);
		if (line[0] && line[0] != COMMENT_CHAR)
		{
			as_a_line(f, sec, code, line);
			if (sec == 2 && !as_scom(line, &code, label, f))
				return (as_free_line(line));
		}
		if ((sec == 0 || sec == 1) && !as_store_nc(line, &sec, &code, &size))
			return (as_free_line(line));
		as_endcomment(line, 1);
		free(line);
	}
	free(line);
	return (as_store_end(&size, &code, f->p, filename));
}
