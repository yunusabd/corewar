/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:53:41 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 01:52:15 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		kill_process(t_vm *vm, t_champ *champ)
{
	int		abs;

	abs = (champ->number < 0 ? -champ->number : champ->number);
	vm->processes--;
	printf("%d PROCESS OF PLAYER %d (%s) died\n",vm->total_cycles, abs, champ->name);
	(vm->processes_counter[abs])--;
	champ->number = -abs;
}
