/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:59:15 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/15 22:26:08 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_ldi(t_vm *vm, t_champ *champ)
{
	intmax_t	reg;
	int			tmp;

	resolve_params(vm, champ, champ->params, 1 + 2);
	resolve_indirect(vm, champ, 1);
	tmp = champ->pc;
	move_pc(&(tmp), (champ->params->p1 + champ->params->p2) % IDX_MOD);
	reg = add_next_octets(vm, &(tmp), REG_SIZE);
	put_reg(vm, champ, champ->params->p3, reg);
	if (reg == 0)
		champ->carry = 1;
	else
		champ->carry = 0;
 	printf("p1: %d, p2: %d, p3: %d\n", champ->params->p1, champ->params->p2, champ->params->p3);
	printf("\nPUT %d in REG %d\n", reg, champ->params->p3);
}
