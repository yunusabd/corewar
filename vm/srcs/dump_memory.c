/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:21:35 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 19:10:02 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_logo(void)
{
	ft_printf(MAG);
	ft_printf("		       __________  ____  _______       _____    ____ \n");
	ft_printf("		     / ____/ __ \\/ __ \\/ ____| |     / /   |  / __ \\\n");
	ft_printf("		   / /   / / / / /_/ / __/  | | /| / / /| | / /_/ /\n");
	ft_printf("		  / /___/ /_/ / _, _/ /___  | |/ |/ / ___ |/ _, _/ \n");
	ft_printf("		  \\____/\\____/_/ |_/_____/  |__/|__/_/  |_/_/ |_|  \n\n");
	ft_printf(RESET);
}

void		dump_vm(t_vm *vm)
{
	int				players;
	intmax_t		lives;
	t_champ			*champ;

	players = 0;
	lives = 0;
	champ = vm->champs;
	while (champ)
	{
		players++;
		lives += champ->live_calls;
		champ = champ->next;
	}
	ft_printf("PROCESSES: %d, TOTAL LIVE CALLS: %d\n", vm->processes, lives);
	ft_printf("CYCLES: %d, CTD: %d\n ", vm->total_cycles, vm->cycles_to_die);
}

void		dump_memory(t_vm *vm)
{
	int		i;
	t_champ	*tmp;

	tmp = vm->champs;
	i = 0;
	print_logo();
	dump_vm(vm);
	while (i < MEM_SIZE)
	{
		if (i % 8 == 0)
			ft_printf("  ");
		if (i % 64 == 0)
			ft_printf("\n");
		tmp = vm->champs;
		while (tmp)
		{
			if (tmp->pc == i && !tmp->dead)
				ft_printf("%s%s", BYEL, BLK);
			tmp = tmp->next;
		}
		ft_printf("%.2x", (unsigned char)vm->memory[i++]);
		ft_printf("%s%s", BRESET, RESET);
		ft_printf(" ");
	}
	ft_printf("\n");
}

void		dump_handler(t_vm *vm)
{
	if (!(vm->cycles % 20))
		ft_printf(CLEAR);
	ft_printf(CUR_RESET);
	dump_memory(vm);
	usleep(100000);
}
