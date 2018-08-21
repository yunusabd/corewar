/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:41:34 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 17:47:35 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static t_champ	*copy_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*new;

	new = create_champ(vm);
	ft_memcpy((void*)new, (void*)champ, sizeof(t_champ));
	ft_memcpy((void*)new->reg, (void*)champ->reg, REG_NUMBER);
	if (!(new->name = ft_strnew(ft_strlen(champ->name))))
		error_exit(vm, "Malloc fail in copy_champ");
	ft_strcpy(new->name, champ->name);
	if (!(new->comment = ft_strnew(ft_strlen(champ->comment))))
		error_exit(vm, "Malloc fail in copy_champ");
	ft_strcpy(new->comment, champ->comment);
	new->bytes = NULL;
	new->data = NULL;
	new->params = NULL;
	new->opcode = 0;
	new->next = NULL;
	return (new);
}

/*
**	Have to move back the pc of the new process by 1, to account for the move-
**	ment in run_champs.
*/

void			op_fork(t_vm *vm, t_champ *champ)
{
	t_champ	*new;

	new = copy_champ(vm, champ);
	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	move_pc(&(champ->pc_tmp), 1);
	get_direct(vm, champ, &(champ->params->p1));
	move_pc(&(new->pc), ((char)champ->params->p1) % IDX_MOD);
	add_process(vm, new);
	vm->processes++;
	vm->processes_counter[champ->number] += 1;
}
