/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:12:54 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/16 19:13:41 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	decrease_cycles(t_vm *vm)
{
	if (vm->ctd > CYCLE_DELTA)
		vm->ctd -= CYCLE_DELTA;
}

void		cycle_check(t_vm *vm)
{
	t_champ	*tmp;
	int		nbr;

	nbr = 1;
	tmp = vm->champs;
	while (tmp)
	{
		if (tmp->live < NBR_LIVE)
			nbr = 0;
		tmp->live = 0;
		tmp = tmp->next;
	}
	if (nbr == 1)
		decrease_cycles(vm);
	else if (vm->cycles / vm->ctd == MAX_CHECKS)
		decrease_cycles(vm);
}
