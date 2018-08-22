/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:03:59 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 19:56:56 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static t_champ	*copy_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*new;

	new = create_champ(vm);
	ft_memcpy((void*)new->reg, (void*)champ->reg, REG_NUMBER);
	if (!(new->name = ft_strnew(ft_strlen(champ->name))))
		error_exit(vm, "Malloc fail in copy_champ");
	ft_strcpy(new->name, champ->name);
	if (!(new->comment = ft_strnew(ft_strlen(champ->comment))))
		error_exit(vm, "Malloc fail in copy_champ");
	ft_strcpy(new->comment, champ->comment);
	new->pc = champ->pc;
	new->bytes = NULL;
	new->number = champ->number;
	new->carry = champ->carry;
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

void			op_lfork(t_vm *vm, t_champ *champ)
{
	t_champ	*new;

	new = copy_champ(vm, champ);
	free(champ->params);
	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	move_pc(&(champ->pc_tmp), 1);
	get_direct(vm, champ, &(champ->params->p1));
	move_pc(&(new->pc), ((char)champ->params->p1));
	add_process(vm, new);
	vm->processes++;
	vm->processes_counter[champ->number] += 1;
}
