/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 01:03:52 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/03 01:42:06 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take a registry, and two indexes (potentially registries) add the two
**	indexes, and use this result as an address where the value of the first
**	parameter will be copied.
*/

void	op_sti(t_vm *vm, t_champ *champ, t_exec *exec)
{
	champ->pc_tmp = champ->pc;
	move_pc(&(champ->pc_tmp), 2);
	exec->src = vm->memory[champ->pc_tmp];
	printf("Register: %d\n", vm->memory[champ->pc_tmp]);
	move_pc(&(champ->pc_tmp), 2);
	exec->res = vm->memory[champ->pc_tmp];
	printf("Direct: %d\n", vm->memory[champ->pc_tmp]);
	move_pc(&(champ->pc_tmp), 2);
	exec->res += vm->memory[champ->pc_tmp];
	printf("Direct: %d\n", vm->memory[champ->pc_tmp]);
	printf("src: %d, res: %d\n", exec->src, exec->res);
}
