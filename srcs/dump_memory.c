/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:21:35 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 20:29:19 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_logo(void)
{
	printf(MAG);
	printf("		       __________  ____  _______       _____    ____ \n");
	printf("		     / ____/ __ \\/ __ \\/ ____| |     / /   |  / __ \\\n");
	printf("		   / /   / / / / /_/ / __/  | | /| / / /| | / /_/ /\n");
	printf("		  / /___/ /_/ / _, _/ /___  | |/ |/ / ___ |/ _, _/ \n");
	printf("		  \\____/\\____/_/ |_/_____/  |__/|__/_/  |_/_/ |_|  \n\n");
	printf(RESET);
}

void		dump_vm(t_vm *vm)
{
	int		players;
	t_champ	*champ;

	players = 0;
	champ = vm->champs;
	while (champ)
	{
		players++;
		champ = champ->next;
	}
	printf("\nAC: %d\n", vm->ac);
	printf("PROCESSES: %d\n", vm->processes);
	printf("CYCLES: %d, CTD: %d\n ", vm->total_cycles, vm->cycles_to_die);
}

void		dump_memory(t_vm *vm)
{
	int		i;
	t_champ	*tmp;

	tmp = vm->champs;
	i = 0;
	print_logo();
	dump_vm(vm);
	while (i <= MEM_SIZE)
	{
		if (i % 8 == 0)
			printf("  ");
		if (i % 64 == 0)
			printf("\n");
		tmp = vm->champs;
		while (tmp)
		{
			if (tmp->pc == i && tmp->number > 0)
				printf("%s%s", BYEL, BLK);
			tmp = tmp->next;
		}
		printf("%.2x", (unsigned char)vm->memory[i++]);
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
	usleep(10000);
}
