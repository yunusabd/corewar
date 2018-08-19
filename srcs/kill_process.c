/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:53:41 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 20:31:08 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		kill_process(t_vm *vm, t_champ *champ)
{
	vm->processes--;
	printf("PROCESS OF PLAYER %d (%s) died\n", champ->number, champ->name);
	(vm->processes_counter[champ->number])--;
	champ->number *= -1;
}
