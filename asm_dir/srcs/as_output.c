/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/25 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

int			as_wfile(t_list_byte **code, char *filename)
{
	int			fd;
	char		*nn;
	int			l;
	t_list_byte	*node;

	node = *code;
	l = ft_strlen(filename);
	if (!(nn = ft_strnew(l + 2)))
		return (as_malloc_error2(code, 1));
	ft_strncpy(nn, filename, l - 1);
	ft_strcpy(nn + l - 1, "cor");
	fd = open(nn, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR
	| S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		as_writing_error(code, nn);
	while (*code)
	{
		write(fd, &((*code)->byte), 1);
		(*code) = (*code)->next;
	}
	ft_printf("Writing output program to %s\n", nn);
	free(nn);
	*code = node;
	return (1);
}

static void	as_print_zeros(int *j, int *l, t_list_byte **list, t_list_byte **n)
{
	*l = *j;
	ft_printf("00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00\n");
	*j -= 16;
	if (*j > 16)
		ft_printf(WHITE "*\n" RESET);
	while (*j > 16)
		*j -= 16;
	*list = *n;
	*l = *l - *j;
	while (*l)
	{
		(*list) = (*list)->next;
		(*l)--;
	}
}

static int	as_print_star(t_list_byte **list, int i)
{
	t_list_byte *node;
	int			j;
	int			k;
	int			l;

	node = *list;
	k = i;
	j = 0;
	l = 0;
	while (!((*list)->byte))
	{
		(*list) = (*list)->next;
		i++;
		j++;
	}
	if (j > 16)
	{
		as_print_zeros(&j, &l, list, &node);
		return (k + (i - k) - j);
	}
	*list = node;
	return (k);
}

static void	as_print_loop(t_list_byte **list, int *i)
{
	static char *colors[10] = {
		WHITE, WHITE, CYAN, MAGENTA,
		GREEN, GREEN, YELLOW, BOLDBLACK, MAGENTA, MAGENTA
		};

	ft_printf(colors[(*list)->type]);
	as_write_byte(*list);
	if (!((*i + 1) % 16))
	{
		ft_putchar('\n');
		*i = as_print_star(list, *i);
	}
	else if (!((*i + 1) % 8))
		ft_putchar(' ');
	ft_printf(RESET);
	*list = (*list)->next;
	(*i)++;
}

int			as_plist(t_list_byte *list)
{
	int			i;
	t_list_byte	*node;

	i = 0;
	node = list;
	while (list)
	{
		if ((i >= 4 + PROG_NAME_LENGTH && i < 8 + PROG_NAME_LENGTH)
		|| (i >= 12 + PROG_NAME_LENGTH + COMMENT_LENGTH
		&& i < 16 + PROG_NAME_LENGTH + COMMENT_LENGTH))
			list->type = 7;
		i++;
		list = list->next;
	}
	list = node;
	i = 0;
	ft_printf("\nallocated bytes: ");
	ft_printf(YELLOW "%d\n\n" RESET, as_code_size(list));
	while (list)
		as_print_loop(&list, &i);
	if ((i + 1) % 16)
		ft_printf("\n\n");
	return (1);
}
