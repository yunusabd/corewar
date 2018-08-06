/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:21:35 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/06 23:06:15 by yabdulha         ###   ########.fr       */
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
		printf("PROCESS CYCLE: %d\n", champ->cycles);
		champ = champ->next;
		i++;
	}
	printf("AC: %d\n", vm->ac);
	printf("PLAYERS: %d\n", vm->players);
	printf("CHAMPS: %d\n", i);
	printf("CYCLES: %d\n", vm->cycles);
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
		if (i % 8 == 0)
			printf("  ");
		if (i % 64 == 0)
			printf("\n");
		tmp = vm->champs;
		while (tmp)
		{
			if (tmp->pc == i)
				printf("%s%s", BYEL, BLK);
			tmp = tmp->next;
		}
		printf("%.2x", vm->memory[i++]);
		printf("%s%s", BRESET, RESET);
		printf(" ");
	}
}

void		dump_handler(t_vm *vm)
{
	if (!(vm->cycles % 20))
		printf(CLEAR);
	printf(CUR_RESET);
	dump_memory(vm);
	usleep(100000);
}
