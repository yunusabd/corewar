/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:16:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/03 01:36:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_opcode(t_vm *vm, t_champ *champ)
{
	champ->op = vm->memory[champ->pc];
	printf("\npc: %d\n", champ->pc);
	printf("OP: %d\n", champ->op);
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

void	get_encoding(char c)
{
	int	i;

	i = (sizeof(c) * 8) - 2;
	while (i > 0)
	{
		print_encoding(((c >> i) & 3), i);
		printf("\n");
		i -= 2;
	}
	printf("[%.2x]", c);
}

void	run_champs(t_vm *vm)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		get_opcode(vm, tmp);
		if (tmp->op == 11)
		{
			//get_encoding(tmp->data[1]);
			op_sti(vm, tmp, init_exec(vm));
		}
		tmp = tmp->next;
	}
}

void	param_handler(t_vm *vm)
{

}
