/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:51:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/07 00:10:11 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take the values of the first two parameters and apply bitwise &, store the
**	result in the register, that is the third parameter.
*/

void	op_ld(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	get_params(vm, champ);
	champ->reg[check_reg(champ->params->p2)] = champ->params->p1;
    champ->cycles = g_op_tab[champ->opcode - 1].cycles;
	champ->carry = 1;
}
