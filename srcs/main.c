/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/20 17:07:54 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

	// add to matrix
	// optimize matrix build... and make a loadinf %
	// norm and build in latest build

int		main(int ac, char **av)
{
	t_vm	*vm;
	int		i;

	vm = create_vm(ac, av);
	fl_get(ac, av, vm);
	load_processes(vm);
	t_champ	*tmp = vm->champs;
	while (tmp)
	{
		printf("Champ %d: %s\n", tmp->number, tmp->name);
		tmp = tmp->next;
	}
	exit(1);
	printf(CLEAR);
	i = 0;
	if ((vm->flags & VIS) || (vm->flags & DUMP))
		i = vm->offset;
	while (vm->processes > 0 && vm->cycles_to_die > 0)
	{
		run_champs(vm);
		fl_write_matrix(vm);
	 	if ((i <= vm->total_cycles && (vm->flags & VIS))
				|| (i == vm->total_cycles && (vm->flags & DUMP)))
		{
			dump_handler(vm);
			if (vm->flags & DUMP)
				error_exit(vm, "OK");
		}
		if ((vm->cycles - vm->cycles_to_die) == 0)
			cycle_check(vm);
		vm->cycles++;
		vm->total_cycles++;
	}
	printf(SHOW_CURSOR);
	judgement_day(vm);
	fl_write_matrix(vm);
	error_exit(vm, "OK");
	return (0);
}
