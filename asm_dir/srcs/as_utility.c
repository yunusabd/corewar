/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/20 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

int	as_code_size(t_list_byte *code)
{
	int i;

	i = 0;
	while (code)
	{
		code = code->next;
		i++;
	}
	return (i);
}

int	as_rlist(t_list_byte **list)
{
	t_list_byte *next;
	t_list_byte *tmp;
	t_list_byte *node;

	next = NULL;
	tmp = NULL;
	node = *list;
	while (node && node->next)
		node = node->next;
	while (*list)
	{
		next = (*list)->next;
		(*list)->next = tmp;
		tmp = *list;
		*list = next;
	}
	*list = node;
	return (1);
}

int	as_reverse_error(t_list_error **list)
{
	t_list_error *next;
	t_list_error *tmp;
	t_list_error *node;

	next = NULL;
	tmp = NULL;
	node = *list;
	while (node && node->next)
		node = node->next;
	while (*list)
	{
		next = (*list)->next;
		(*list)->next = tmp;
		tmp = *list;
		*list = next;
	}
	*list = node;
	return (1);
}

int	as_label_list_size(t_list_label *label)
{
	int	i;

	i = 0;
	while (label)
	{
		i++;
		label = label->next;
	}
	return (i);
}

int	as_get_op_pos(char *line, int i)
{
	int	j;

	j = 15;
	while (j >= 0)
	{
		if (!ft_strncmp(
		g_op_tab[j].opname, line + i, ft_strlen(g_op_tab[j].opname)))
			break ;
		j--;
	}
	return (j);
}
