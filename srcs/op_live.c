/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:55:30 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 23:46:01 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

/*
**	Get the player number (direct parameter).
**	Increase live calls for that player.
**	Set pointer "last_live" in vm to the player.
**	Increase live calls for process.
*/

void	op_live(t_vm *vm, t_champ *champ)
{
	t_champ	*find;

	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	get_direct(vm, champ, &(champ->params->p1));
	if ((find = find_champ(vm, champ->params->p1)))
	{
		vm->last_live = find;
		vm->lives_counter[find->number]++;
		if (!(vm->flags & MATRIX))
			ft_printf("A process shows that player %d (%s) is alive\n",\
				find->number, find->name);
	}
	(champ->live_calls)++;
}
