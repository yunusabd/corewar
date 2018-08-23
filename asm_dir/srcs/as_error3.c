/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/20 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <unistd.h>

static void	as_dlnode(t_list_error **node, t_list_error **error)
{
	free((*node)->message);
	free((*node)->line);
	free(*node);
	*node = *error;
	if (!(*error))
		return ;
	*error = (*error)->next;
}

static void	as_dlone(t_list_error **node, t_list_error **err, char *l)
{
	if ((*err)->type == 4 && !ft_strcmp((*node)->message, l))
	{
		free((*err)->message);
		free((*err)->line);
		free((*err));
		*err = NULL;
	}
}

static void	as_dlone2(t_list_error **prev, t_list_error **err, char *l)
{
	if ((*err)->type == 4 && !ft_strcmp((*err)->message, l))
	{
		free((*err)->message);
		free((*err)->line);
		(*prev)->next = (*err)->next;
		free(*err);
		*err = *prev;
	}
}

void		as_del_label_errors(t_list_error **error, char *line, int i)
{
	t_list_error	*node;
	t_list_error	*prev;
	char			c;

	c = line[i];
	line[i] = '\0';
	node = *error;
	if (*error && !((*error)->next))
		as_dlone(&node, error, line);
	else if (*error)
	{
		(*error) = (*error)->next;
		while (node && node->type == 4 && !ft_strcmp(node->message, line))
			as_dlnode(&node, error);
		prev = node;
		while (*error)
		{
			as_dlone2(&prev, error, line);
			prev = *error;
			*error = (*error)->next;
		}
		*error = node;
	}
	line[i] = c;
}

char		*as_label_sug(char *str, t_list_label *label)
{
	int				highest;
	t_list_label	*pos;
	int				save;

	highest = 0;
	while (label)
	{
		if ((save = as_cmd_comp(label->name, str)) > highest)
		{
			pos = label;
			highest = save;
		}
		label = label->next;
	}
	if (highest > 1)
		return (pos->name);
	else
		return (NULL);
}
