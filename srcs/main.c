/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 01:40:04 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

	// add to matrix
	// optimize matrix build... and make a loadinf %
	// norm and build in latest build

static void	run_vm(t_vm *vm)
{
	int	i;

	i = 0;
	if ((vm->flags & VIS) || (vm->flags & DUMP))
		i = vm->offset;
	while (vm->cycles < 5001 && vm->processes > 0 && vm->cycles_to_die > 0)
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
}

int			main(int ac, char **av)
{
	t_vm	*vm;

	vm = create_vm(ac, av);
	fl_get(ac, av, vm);
	load_processes(vm);
	printf(CLEAR);
	t_champ	*tmp = vm->champs;
	while (tmp)
	{
		tmp->reg[0] < 0 ? tmp->reg[0] *= -1 : 0;
		tmp = tmp->next;
	}
	run_vm(vm);
	judgement_day(vm);
	fl_write_matrix(vm);
	printf(SHOW_CURSOR);
	error_exit(vm, "OK");
	return (0);
}
