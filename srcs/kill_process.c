/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:53:41 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 13:30:28 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

void		kill_process(t_vm *vm, t_champ *champ)
{
	int		abs;

	abs = (champ->number < 0 ? -champ->number : champ->number);
	vm->processes--;
	if (vm->flags & DEBUG)
		ft_printf("%d PROCESS OF PLAYER %d (%s) died\n",\
				vm->total_cycles, abs, champ->name);
	(vm->processes_counter[abs])--;
	champ->number = -abs;
}
