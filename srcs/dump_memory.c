/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:21:35 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 22:16:41 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		dump_vm(t_vm *vm)
{
	int		i;
	t_champ	*champ;

	i = 0;
	champ = vm->champs;
	while (champ)
	{
		champ = champ->next;
		i++;
	}
	printf("AC: %d\n", vm->ac);
	printf("PLAYERS: %d\n", vm->players);
	printf("CHAMPS: %d\n", i);
}

void		dump_memory(t_vm *vm)
{
	int		i;
	t_champ	*tmp;

	tmp = vm->champs;
	i = 0;
	dump_vm(vm);
	while(i < MEM_SIZE)
	{
		tmp = vm->champs;
		while (tmp)
		{
			if (tmp->pc == i)
				printf(RED);
			tmp = tmp->next;
		}
		if (i % 8 == 0)
			printf("  ");
		if (i % 64 == 0)
			printf("\n");
		printf("%.2x ", vm->memory[i++]);
		printf(RESET);
	}
}
