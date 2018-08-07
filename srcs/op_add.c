/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:12:20 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/07 18:23:55 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take three registries, add up the first two and store the result in third.
*/

void		op_add(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	get_params(vm, champ);
	resolve_params(vm, champ, champ->params, 3);
	p = champ->params;
	champ->reg[check_reg(champ->params->p3)] = champ->params->p1
		+ champ->params->p2;
	champ->cycles = g_op_tab[champ->opcode - 1].cycles;
	champ->carry = 1;
}
