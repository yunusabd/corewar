/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:12:54 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/17 11:43:44 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	decrease_cycles(t_vm *vm)
{
//	if (vm->ctd > CYCLE_DELTA)
	vm->cycles_to_die -= CYCLE_DELTA;
	vm->checks = 0;
	printf("\nDECREASED CYCLE TO %d\n", vm->cycles_to_die);
}

void		cycle_check(t_vm *vm)
{
	t_champ	*tmp;
	int		nbr;

	nbr = 1;
	tmp = vm->champs;
	while (tmp)
	{
		if (tmp->live_calls < NBR_LIVE)
			nbr = 0;
		tmp->live_calls = 0;
		tmp = tmp->next;
	}
	if (nbr == 1)
		decrease_cycles(vm);
	else if (vm->checks == MAX_CHECKS)
	{
		decrease_cycles(vm);
		vm->checks = 0;
	}
	vm->checks++;
	vm->cycles = 0;
}
