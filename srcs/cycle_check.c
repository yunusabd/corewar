/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:12:54 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 19:14:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	decrease_cycles(t_vm *vm)
{
	vm->cycles_to_die -= CYCLE_DELTA;
	vm->checks = -1;
}

static void	check_live_calls(t_vm *vm)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		if (tmp->live_calls == 0 && tmp->number > 0)
			kill_process(vm, tmp);
		else if (tmp->live_calls > 0 && tmp->number > 0)
			tmp->live_calls = 0;
		tmp = tmp->next;
	}
}

static int	check_players(t_vm *vm)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < MAX_PLAYERS + 1)
	{
		if (vm->processes_counter[i] > 0)
			counter++;
		i++;
	}
	return (counter);
}

void		cycle_check(t_vm *vm)
{
	t_champ			*tmp;
	intmax_t		nbr;

	nbr = 0;
	tmp = vm->champs;
	while (tmp)
	{
		nbr += tmp->live_calls;
		tmp = tmp->next;
	}
	if (nbr >= NBR_LIVE || vm->checks == MAX_CHECKS)
		decrease_cycles(vm);
	check_live_calls(vm);
	if (check_players(vm) == 0 || (check_players(vm) < 2 && vm->players > 1))
	{
		judgement_day(vm);
		error_exit(vm, "OK");
	}
	vm->checks++;
	vm->cycles = 0;
}
