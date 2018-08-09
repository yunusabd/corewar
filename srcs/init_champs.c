/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:16:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/09 15:49:21 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_opcode(t_vm *vm, t_champ *champ)
{
	champ->opcode = vm->memory[champ->pc];
	champ->cycles = g_op_tab[champ->opcode - 1].cycles;
	printf("\npc: %d\n", champ->pc);
	printf("OP: %d\n", champ->opcode);
	printf("operation: %s\n", g_op_tab[vm->memory[champ->pc] - 1].opname);
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
	void	(*f[16])(t_vm *vm, t_champ *champ) = { 0, op_live, op_ld, 0, op_add,
		0, op_and, 0, 0, op_zjmp, 0, op_sti, op_fork, 0, 0, 0 };

	tmp = vm->champs;
	while (tmp)
	{
		if ((tmp->opcode && tmp->cycles))
			tmp->cycles--;
		else if (!(tmp->opcode))
			get_opcode(vm, tmp);
		else
		{
			o = tmp->opcode;
			if (o == 11 || o == 6 || o == 2 || o == 4)
			{
				move_pc(&(tmp->pc), 1);
				tmp->encoding_byte = vm->memory[tmp->pc];
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
				op_zjmp(vm, tmp);
			else if (tmp->opcode == 12)
			{
				move_pc(&(tmp->pc), 1);
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
