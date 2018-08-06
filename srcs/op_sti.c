/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:07:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/06 22:39:31 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take a registry, and two indexes (potentially registries) add the two
**	indexes, and use this result as an address where the value of the first
**	parameter will be copied.
*/

void	op_sti(t_vm *vm, t_champ *champ)
{
	int		i;
	int		tmp;

	get_params(vm, champ);
	resolve_params(vm, champ, champ->params, 3);
	tmp = champ->pc;
	champ->params->p2 += champ->params->p3;
	move_pc(&(tmp), champ->params->p2 + REG_SIZE - 1);
	i = 0;
	while (i < REG_SIZE)
	{
		move_pc(&(tmp), -1);
		vm->memory[tmp] = (champ->params->p1 >> 8 * i) & 255;
		i++;
	}
    champ->cycles = g_op_tab[champ->opcode - 1].cycles;
}
