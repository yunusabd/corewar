/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/18 19:50:58 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	t_vm	*vm;
	int		i;

	vm = create_vm(ac, av);
	while (ac-- > 1)
		reader(vm, ac, av[ac]);
	load_processes(vm);
	printf(CLEAR);
	i = 0;
	while (vm->processes > 0 && vm->cycles_to_die > 0)
	{
		run_champs(vm);
	 	if (i <= vm->total_cycles)
			dump_handler(vm);
		if ((vm->cycles - vm->cycles_to_die) == 0)
			cycle_check(vm);
		vm->cycles++;
		vm->total_cycles++;
//		printf("FIRST PLAYER: %d (%s)\n", vm->champs->number, vm->champs->name);
	}
	printf(SHOW_CURSOR);
	judgement_day(vm);
	return (0);
}
