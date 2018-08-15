/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:41:34 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/15 17:45:58 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Have to move back the pc of the new process by 1, to account for the move-
**	ment in run_champs.
*/

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
	new->number = champ->number;
	new->pc = champ->pc;
	get_direct(vm, champ, &(champ->params->p1));
	move_pc(&(new->pc), ((char)champ->params->p1 - 1) % IDX_MOD);
	add_champ(vm, new);
	new->opcode = 0;
	printf("NEW PC: %d\n", new->pc);
	printf("PLAYER %d FORKED\n", champ->number);
}
