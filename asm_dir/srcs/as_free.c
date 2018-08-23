/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"

int	as_free_line(char *line)
{
	if (line)
		free(line);
	return (0);
}

int	as_free_error(t_list_error **list)
{
	t_list_error	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->line)
			free((*list)->line);
		if ((*list)->message)
			free((*list)->message);
		free(*list);
		*list = tmp;
	}
	return (0);
}

int	as_free_lab_fla(t_list_label **list, t_flags *flags)
{
	t_list_label	*tmp;

	while (*list)
	{
		tmp = *list;
		if ((*list)->name)
			free((*list)->name);
		free(*list);
		*list = tmp->next;
	}
	if (flags)
		free(flags);
	return (1);
}

int	as_free(t_list_byte **list)
{
	t_list_byte *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	return (1);
}
