/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:59:15 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 13:35:02 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_ldi(t_vm *vm, t_champ *champ)
{
	intmax_t	reg;
	int			tmp;

	resolve_params(champ, champ->params, 1 + 2);
	resolve_indirect(vm, champ, 1);
	tmp = champ->pc;
	move_pc(&(tmp), (champ->params->p1 + champ->params->p2) % IDX_MOD);
	reg = add_next_octets(vm, &(tmp), REG_SIZE);
	put_reg(vm, champ, champ->params->p3, reg);
}
