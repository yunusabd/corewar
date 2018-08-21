/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 00:05:08 by yabdulha         ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_vm	*vm;
	t_champ	*tmp;

	ft_printf(CLEAR);
	vm = create_vm(ac, av);
	fl_get(ac, av, vm);
	load_processes(vm);
	tmp = vm->champs;
	while (tmp)
	{
		tmp->reg[0] < 0 ? tmp->reg[0] *= -1 : 0;
		tmp = tmp->next;
	}
	run_vm(vm);
	judgement_day(vm);
	fl_write_matrix(vm);
	error_exit(vm, "OK");
	return (0);
}
