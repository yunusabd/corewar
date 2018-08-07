/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:51:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/07 18:21:53 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Write the value in the first arg to the register specified in the second arg.
*/

void	op_ld(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	get_params(vm, champ);
	p = champ->params;
	champ->reg[check_reg(champ->params->p2)] = champ->params->p1;
    champ->cycles = g_op_tab[champ->opcode - 1].cycles;
	champ->carry = 1;
}