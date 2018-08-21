/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:16:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 15:14:59 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	get_opcode(t_vm *vm, t_champ *champ)
{
	if (vm->memory[champ->pc] < 1 || champ->opcode > 16)
		move_pc(&(champ->pc), 1);
	else
	{
		champ->opcode = vm->memory[champ->pc];
		champ->cycles = g_op_tab[champ->opcode - 1].cycles;
	}
}

static void	run_normal(t_vm *vm, t_champ *tmp)
{
	static void	(*f[17])(t_vm *vm, t_champ *champ) = { 0, op_live, op_ld, op_st,
		op_add, op_sub, op_and, op_or, op_xor, op_zjmp, op_ldi,
		op_sti, op_fork, op_lld, op_lldi, op_lfork, op_aff };

	tmp->pc_tmp = tmp->pc;
	move_pc(&(tmp->pc_tmp), 1);
	tmp->encoding_byte = vm->memory[tmp->pc_tmp];
	get_params(vm, tmp);
	f[tmp->opcode](vm, tmp);
	tmp->pc = tmp->pc_tmp;
}

static void	run_other(t_vm *vm, t_champ *tmp)
{
	if (tmp->opcode == 1)
	{
		move_pc(&(tmp->pc), 1);
		op_live(vm, tmp);
		tmp->pc = tmp->pc_tmp;
	}
	else if (tmp->opcode == 9)
	{
		move_pc(&(tmp->pc), 1);
		op_zjmp(vm, tmp);
	}
	else if (tmp->opcode == 12)
	{
		op_fork(vm, tmp);
		tmp->pc = tmp->pc_tmp;
	}
	else if (tmp->opcode == 15)
	{
		op_lfork(vm, tmp);
		tmp->pc = tmp->pc_tmp;
	}
}

void		run_champs(t_vm *vm)
{
	int			o;
	t_champ		*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		if ((tmp->opcode && tmp->cycles))
			tmp->cycles--;
		else if (tmp->number > 0 && !(tmp->opcode))
			get_opcode(vm, tmp);
		if (tmp->opcode > 0 && !tmp->cycles && tmp->number > 0)
		{
			o = tmp->opcode;
			if ((o > 1 && o < 9) || (o > 12 && o < 15) || o == 10 || o == 11
					|| o == 16)
				run_normal(vm, tmp);
			else
				run_other(vm, tmp);
			if (tmp->opcode)
				free(tmp->params);
			tmp->params = NULL;
			tmp->opcode = 0;
		}
		tmp = tmp->next;
	}
}
