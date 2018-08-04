/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 01:03:52 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/04 22:41:17 by yabdulha         ###   ########.fr       */
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

/*
**	Jump two spaces to first parameter (register)
*/

void	op_sti(t_vm *vm, t_champ *champ, t_exec *exec)
{
	int		i;

	champ->pc_tmp = champ->pc;
	move_pc(&(champ->pc_tmp), 2);
	exec->src = vm->memory[champ->pc_tmp];
	exec->res = add_two_octets(vm, champ->pc_tmp + 1);
	exec->res += add_two_octets(vm, champ->pc_tmp + 3);
	champ->pc_tmp = champ->pc;
	move_pc(&(champ->pc_tmp), exec->res + REG_SIZE - 1);
	i = 0;
	while (i < REG_SIZE)
	{
		vm->memory[champ->pc_tmp - i]
			= (champ->reg[check_reg(exec->src)] >> 8 * i) & 255;
		i++;
	}
}
