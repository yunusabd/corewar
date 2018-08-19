/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 02:23:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/15 05:05:27 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

void	op_lldi(t_vm *vm, t_champ *champ)
{
	int	reg;
	int	tmp;

	resolve_params(vm, champ, champ->params, 1 + 2);
	resolve_indirect(vm, champ, 1);
	tmp = champ->pc;
	move_pc(&(tmp), (champ->params->p1 + champ->params->p2));
	reg = add_next_octets(vm, &(tmp), REG_SIZE);
	put_reg(vm, champ, champ->params->p3, reg);
	if (reg == 0)
		champ->carry = 1;
	else
		champ->carry = 0;
//	printf("p1: %d, p2: %d, p3: %d\n", champ->params->p1, champ->params->p2, champ->params->p3);
	if (!(vm->flags & MATRIX))
		printf("\nPUT %d in REG %d\n", reg, champ->params->p3);
}
