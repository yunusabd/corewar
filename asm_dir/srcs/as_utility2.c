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

void	as_write_bytes(t_list_byte **code, int info, int n)
{
	int			i;
	t_list_byte	*node;

	node = *code;
	i = 0;
	while (i < n)
	{
		(*code)->byte = (info >> (8 * i)) & 0xff;
		(*code) = (*code)->next;
		i++;
	}
	*code = node;
}

int		as_add_bytes(t_list_byte **code, int n, int type)
{
	while (n)
	{
		if (!as_add_byte(code, 0, type))
			return (0);
		n--;
	}
	return (1);
}

int		as_add_byte(t_list_byte **code, unsigned char byte, int type)
{
	t_list_byte	*new;

	if (!(new = (t_list_byte *)malloc(sizeof(*new))))
		return (as_malloc_error2(code, 4));
	new->next = *code;
	*code = new;
	(*code)->byte = byte;
	(*code)->type = type;
	return (1);
}

int		as_add_label(t_list_label **label, char *line, int i, int pos)
{
	t_list_label	*new;

	if (!(new = (t_list_label *)malloc(sizeof(*new))))
	{
		as_free_lab_fla(label, NULL);
		return (as_malloc_error2(NULL, 3));
	}
	new->next = *label;
	*label = new;
	if (!((*label)->name = ft_strnew(i)))
	{
		as_free_lab_fla(label, NULL);
		return (as_malloc_error2(NULL, 3));
	}
	ft_strncpy((*label)->name, line, i);
	(*label)->pos = pos;
	return (1);
}

int		as_cmd_comp(char *cmd, char *str)
{
	int	i;
	int	j;
	int	k;
	int	ret;

	ret = 0;
	j = 0;
	k = 0;
	while ((j < 5 && str[j] && !ft_isspace(str[j]) && str[j] != cmd[k])
	|| (str[j] && str[j + 1] && str[j + 1] == cmd[k]))
		j++;
	i = ft_strlen(cmd);
	while (i && str[j] && !ft_isspace(str[j]))
	{
		if (cmd[k] == str[j])
			ret++;
		else if (k > 1)
			k--;
		j++;
		k++;
		i--;
	}
	return (ret);
}
