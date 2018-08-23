/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:30:08 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/18 16:30:09 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static void	fl_find_unique(int *f, t_champ **n, t_champ **champ, t_champ *tmp)
{
	*f = 0;
	*n = *champ;
	while (*champ)
	{
		if (tmp->number == (*champ)->number && tmp->opcode == (*champ)->opcode)
		{
			(*champ)->carry = (*champ)->carry + 1;
			*f = 1;
		}
		*champ = (*champ)->next;
	}
	*champ = *n;
}

void		fl_free_champ(t_champ **champ)
{
	t_champ *tmp;

	while (*champ)
	{
		tmp = (*champ)->next;
		free(*champ);
		(*champ) = tmp;
	}
}

void		fl_write_data_num(int data, t_vm *vm, int fd)
{
	char *num;

	if (!(num = ft_itoa(data)))
		error_exit(vm, "malloc failure in fl_write_data_num");
	write(fd, num, ft_strlen(num));
	free(num);
}

void		fl_make_champ(t_champ **champ, t_vm *vm)
{
	t_champ *tmp;
	t_champ *node;
	t_champ *new;
	int		found;

	tmp = vm->champs;
	*champ = NULL;
	while (tmp)
	{
		fl_find_unique(&found, &node, champ, tmp);
		if (!found && tmp->number > 0)
		{
			if (!(new = (t_champ *)malloc(sizeof(t_champ))))
				error_exit(vm, "malloc failure in fl_make_champ");
			new->carry = 0;
			new->number = tmp->number;
			new->opcode = tmp->opcode;
			new->next = (*champ);
			(*champ) = new;
		}
		tmp = tmp->next;
	}
}

void		fl_get_val(t_champ **tmp, t_vm *vm, int *val, int l)
{
	*tmp = vm->champs;
	*val = (unsigned char)(vm->memory)[l];
	while (*tmp)
	{
		*val = ((*tmp)->pc == l) ? *val + 1000 : *val;
		*tmp = (*tmp)->next;
	}
}
