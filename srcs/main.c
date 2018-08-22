/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 01:30:01 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static void	run_vm(t_vm *vm)
{
	int	i;

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
}

static void	init_vm(t_vm *vm)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		if (!(vm->flags & MATRIX))
			ft_printf("PLAYER %d: %s\n", tmp->number, tmp->name);
		vm->players++;
		vm->processes++;
		vm->processes_counter[tmp->number]++;
		tmp->reg[0] = tmp->number;
		tmp = tmp->next;
	}
}

int			main(int ac, char **av)
{
	t_vm	*vm;

	ft_printf(CLEAR);
	vm = create_vm(ac, av);
	fl_get(ac, av, vm);
	init_vm(vm);
	if (!(vm->flags & MATRIX))
		ft_printf("PLAYERS %d, PROCESSES: %d\n", vm->players, vm->processes);
	load_processes(vm);
	run_vm(vm);
	judgement_day(vm);
	if (!(vm->flags & MATRIX))
		ft_printf("cycles: %d\n", vm->total_cycles);
	fl_write_matrix(vm);
	error_exit(vm, "OK");
	return (0);
}
