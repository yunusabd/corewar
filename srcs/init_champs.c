/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:16:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/16 14:15:47 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_opcode(t_vm *vm, t_champ *champ)
{
	champ->opcode = vm->memory[champ->pc];
	if (champ->opcode < 1 || champ->opcode > 16)
		move_pc(&(champ->pc), 1);
	champ->cycles = g_op_tab[champ->opcode - 1].cycles;
//	Can cause segfault if OP does not exist.
/*	
	printf("\npc: %d\n", champ->pc);
	printf("OP: %d\n", champ->opcode);
	printf("operation: %s\n", g_op_tab[vm->memory[champ->pc] - 1].opname);
*/
}

void	print_encoding(int n, int i)
{
	char	*pos;
	char	*type[3] = {"register", "direct", "indirect"};

	if (i == 6)
		pos = "First param";
	else if (i == 4)
		pos = "Second param";
	else if (i == 2)
		pos = "Third param";
	printf("%s: %s\n", pos, type[n - 1]);
}

void	run_champs(t_vm *vm)
{
	int		o;
	t_champ	*tmp;
	void	(*f[17])(t_vm *vm, t_champ *champ) = { 0, op_live, op_ld, op_st,
		op_add, op_sub, op_and, op_or, op_xor, op_zjmp, op_ldi,
		op_sti, op_fork, op_lld, op_lldi, op_lfork, 0 };

	tmp = vm->champs;
	while (tmp)
	{
		if ((tmp->opcode && tmp->cycles))
			tmp->cycles--;
		else if (!(tmp->opcode))
			get_opcode(vm, tmp);
		if (tmp->opcode > 0 && !tmp->cycles)
		{
			o = tmp->opcode;
			if (o == 2 || o == 3 || o == 4 || o == 5 || o == 6 || o == 7
					|| o == 8 || o == 10 || o == 11)
			{
				tmp->pc_tmp = tmp->pc;
				move_pc(&(tmp->pc_tmp), 1);
				tmp->encoding_byte = vm->memory[tmp->pc_tmp];
				get_params(vm, tmp);
				f[tmp->opcode](vm, tmp);
				tmp->pc = tmp->pc_tmp;
			}
			else if (tmp->opcode == 1)
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
			if (tmp->opcode)
			{
				free(tmp->params);
				tmp->params = NULL;
			}
			tmp->opcode = 0;
		}
		tmp = tmp->next;
	}
}
