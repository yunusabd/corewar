/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:12:54 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 19:21:46 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

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
		if (tmp->live_calls == 0 && !tmp->dead)
			kill_process(vm, tmp);
		else if (tmp->live_calls > 0 && !tmp->dead)
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
	if (!(vm->flags & MATRIX) && check_players(vm) == 0)
	{
		judgement_day(vm);
		error_exit(vm, "OK");
	}
	vm->checks++;
	vm->cycles = 0;
}
