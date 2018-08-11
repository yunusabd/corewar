/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:49:52 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/11 18:20:47 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take the values of the first two parameters and apply bitwise ^, store the
**	result in the register, that is the third parameter.
*/

void	op_xor(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	p = champ->params;
	resolve_params(vm, champ, champ->params, 3);
	p = champ->params;
	champ->reg[check_reg(p->p3)] = p->p1 ^ p->p2;
	champ->carry = 1;
}
