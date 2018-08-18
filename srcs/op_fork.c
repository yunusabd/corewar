/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:41:34 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/18 17:39:07 by yabdulha         ###   ########.fr       */
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
	ft_memcpy((void*)new->reg, (void*)champ->reg, REG_NUMBER);
	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	move_pc(&(champ->pc_tmp), 1);
	new->number = champ->number;
	new->pc = champ->pc;
	get_direct(vm, champ, &(champ->params->p1));
	move_pc(&(new->pc), ((char)champ->params->p1) % IDX_MOD);
	add_process(vm, new);
	vm->processes++;
	vm->processes_counter[champ->number] += 20;
	new->opcode = 0;
	printf("NEW PC: %d\n", new->pc);
	printf("PLAYER %d FORKED\n", champ->number);
}
