/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:55:30 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/17 12:01:54 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_live(t_vm *vm, t_champ *champ)
{
	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	get_direct(vm, champ, &(champ->params->p1));
	champ->live_calls++;
	vm->last_live = champ;
	printf("A process shows that player %d (%s) is alive\n", champ->number, champ->name);
//	usleep(1000000);
}
