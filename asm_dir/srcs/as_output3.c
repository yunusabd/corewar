/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_output3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/28 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

void		as_a_line(t_flags *f, int sec, t_list_byte *code, char *line)
{
	if (f->a && sec == 2)
	{
		ft_printf(YELLOW "\n%d: " RESET, as_code_size(code) - 2192);
		ft_printf(BOLDBLACK "%s\n" RESET, line);
	}
}

void		as_write_byte(t_list_byte *code)
{
	if (code->byte < 16)
		ft_printf("0");
	ft_printf("%x ", code->byte);
}

int			as_flags_loop(t_flags **flags, int argc, char **argv, int *pos)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((argv[i][0] != '-' || ft_strlen(argv[i]) != 2) && i != (*pos))
			return (as_err3(USAGE));
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'w' && !((*flags)->v))
				(*flags)->v = 1;
			else if (argv[i][1] == 'W' && !((*flags)->v))
				(*flags)->v = 1;
			else if (argv[i][1] == 'p' && !((*flags)->p))
				(*flags)->p = 1;
			else if (argv[i][1] == 'a' && !((*flags)->a))
				(*flags)->a = 1;
			else
				return (as_err3(USAGE));
		}
		i++;
	}
	return (1);
}
