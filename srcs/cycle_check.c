/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:12:54 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/17 16:33:54 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	decrease_cycles(t_vm *vm)
{
	vm->cycles_to_die -= CYCLE_DELTA;
	vm->checks = -1;
	printf("\nDECREASED CYCLE TO %d\n", vm->cycles_to_die);
}

void		check_live_calls(t_vm *vm)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		if (tmp->live_calls == 0)
		{
			vm->processes--;
			tmp->number *= -1;
			printf("PROCESS OF PLAYER %d (%s) died\n", tmp->number, tmp->name);
			exit(1);
		}
		else if (tmp->live_calls > 0)
			tmp->live_calls = 0;
		tmp = tmp->next;
	}
}

void		cycle_check(t_vm *vm)
{
	t_champ	*tmp;
	int		nbr;

	printf("cylce_check\n");
	nbr = 1;
	tmp = vm->champs;
	while (tmp)
	{
		if (tmp->live_calls < NBR_LIVE)
			nbr = 0;
		tmp = tmp->next;
	}
	if (nbr == 1 || vm->checks == MAX_CHECKS)
		decrease_cycles(vm);
	check_live_calls(vm);
	vm->checks++;
	vm->cycles = 0;
}
