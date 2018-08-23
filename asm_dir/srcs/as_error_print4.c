/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_print4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/05 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

static void	as_putspace(char *line, int i)
{
	char	c;

	c = (ft_isspace(line[i])) ? (line[i]) : (' ');
	write(2, &c, 1);
}

static void	as_err_line_dots(char *line)
{
	char	c;

	c = line[MAX_ERROR_SIZE - 1];
	line[MAX_ERROR_SIZE - 1] = '\0';
	ft_putstr_fd(line, 2);
	ft_putstr_fd("...\n", 2);
	line[MAX_ERROR_SIZE - 1] = c;
}

static void	as_write_long_err(char *line, int column_nr)
{
	char c;

	c = line[MAX_ERROR_SIZE + column_nr - 6];
	line[MAX_ERROR_SIZE + column_nr - 6] = '\0';
	ft_putstr_fd(line + column_nr - 5, 2);
	ft_putstr_fd("...\n", 2);
	line[MAX_ERROR_SIZE + column_nr - 6] = c;
}

void		as_write_err_line(char *line, int column_nr)
{
	if (ft_strlen(line) > MAX_ERROR_SIZE && column_nr < MAX_ERROR_SIZE)
		as_err_line_dots(line);
	else if (ft_strlen(line) > MAX_ERROR_SIZE && column_nr >= MAX_ERROR_SIZE)
	{
		ft_putstr_fd("...", 2);
		if (ft_strlen(line + column_nr - 5) > MAX_ERROR_SIZE)
			as_write_long_err(line, column_nr);
		else
		{
			ft_putstr_fd(line + column_nr - 5, 2);
			ft_putstr_fd("\n", 2);
		}
	}
	else
	{
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\n", 2);
	}
}

void		as_write_err_sign(char *line, int column_nr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(line) > MAX_ERROR_SIZE && column_nr >= MAX_ERROR_SIZE)
	{
		i = column_nr - 5;
		while (j < 7)
		{
			as_putspace(line, i);
			i++;
			j++;
		}
	}
	else
	{
		while (i < column_nr - 1)
		{
			as_putspace(line, i);
			i++;
		}
	}
	ft_putstr_fd(GREEN "^\n" RESET, 2);
}
