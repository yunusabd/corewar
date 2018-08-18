/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:12:54 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/18 18:12:43 by yabdulha         ###   ########.fr       */
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
	intmax_t	*i;

	tmp = vm->champs;
	while (tmp)
	{
		if (tmp->live_calls == 0 && tmp->number > 0)
		{
			vm->processes--;
			printf("PROCESS OF PLAYER %d (%s) died\n", tmp->number, tmp->name);
			(vm->processes_counter[tmp->number])--;
			tmp->number *= -1;
			i = vm->processes_counter;
			printf("[%d] [%d] [%d] [%d]\n", i[1], i[2], i[3], i[4]);
			printf("\ncycles: %d\n", vm->cycles);
			tmp = vm->champs;
		}
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
		if (vm->processes_counter > 0)
			counter++;
		i++;
	}
}

void		cycle_check(t_vm *vm)
{
	t_champ	*tmp;
	int		nbr;

	printf("\ncylce_check, cycle number %d\n", vm->total_cycles);
	nbr = 0;
	tmp = vm->champs;
	while (tmp)
	{
		if (tmp->live_calls >= NBR_LIVE)
			nbr = 1;
		tmp = tmp->next;
	}
	if (nbr == 1 || vm->checks == MAX_CHECKS)
		decrease_cycles(vm);
	check_live_calls(vm);
	if (check_players(vm < 2))
		printf("PLAYER %d %s won.\n", vm->last_live->number, vm->last_live->name);
	vm->checks++;
	vm->cycles = 0;
}
