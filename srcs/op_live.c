/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:55:30 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/18 17:52:12 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_live(t_vm *vm, t_champ *champ)
{
	t_champ	*find;
	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	get_direct(vm, champ, &(champ->params->p1));
	if ((find = find_champ(vm, champ->params->p1)))
	{
		vm->last_live = find;
		find->live_calls++;
		printf("\nA process shows that player %d (%s) is alive\n", find->number,
				find->name);
	}
	champ->live_calls++;
//	usleep(1000000);
}
