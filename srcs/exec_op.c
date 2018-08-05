/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 01:03:52 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 19:06:20 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		add_two_octets(t_vm *vm, int pc)
{
	int	res;

	res = vm->memory[pc];
	res = res << 8;
	move_pc(&pc, 1);
	res |= vm->memory[pc];
	return (res);
}

/*
**	Take a registry, and two indexes (potentially registries) add the two
**	indexes, and use this result as an address where the value of the first
**	parameter will be copied.
*/

void	op_sti(t_vm *vm, t_champ *champ)
{
	int		i;

	get_params(vm, champ);
	champ->pc_tmp = champ->pc;
	champ->exec->p2 += champ->exec->p3;
	move_pc(&(champ->pc_tmp), champ->exec->p2 + REG_SIZE - 1);
	i = 0;
	while (i < REG_SIZE)
	{
		move_pc(&(champ->pc_tmp), -1);
		vm->memory[champ->pc_tmp]
			= (champ->reg[check_reg(champ->exec->p1)] >> 8 * i) & 255;
		i++;
	}
}
