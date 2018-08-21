/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:53:41 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 22:18:59 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

void		kill_process(t_vm *vm, t_champ *champ)
{
	vm->processes--;
	if (vm->flags & DEBUG)
		ft_printf("%d PROCESS OF PLAYER %d (%s) died\n",\
				vm->total_cycles, champ->number, champ->name);
	(vm->processes_counter[champ->number])--;
	champ->dead = 1;
}
