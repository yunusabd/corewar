/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:41:34 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/09 15:46:00 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	insert_champ(t_vm *vm, t_champ *champ)
{
	int	i;

	i = 0;
	while (i < champ->size)
	{
		vm->memory[champ->pc + i] = (unsigned char)champ->data[i];
		i++;
	}
	usleep(100000);
}

void		op_fork(t_vm *vm, t_champ *champ)
{
	t_champ	*new;

	new = create_champ(vm);
	memcpy((void*)new, (void*)champ, sizeof(t_champ));
	if (!(new->data = ft_strnew(champ->size)))
		error_exit(vm, "Error in op_fork");
	ft_memcpy((void*)new->data, (void*)champ->data, champ->size);
	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	get_direct(vm, champ, &(champ->params->p1));
	move_pc(&(new->pc), champ->params->p1 % IDX_MOD);
	insert_champ(vm, new);
	add_champ(vm, new);
	printf("PLAYER %d FORKED\n", champ->number);
}
