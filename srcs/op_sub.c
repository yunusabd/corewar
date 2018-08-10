/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:41:43 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/10 15:42:19 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take three registries, substracts the second from the first parameter
**	and store the result in the third one, which is a register.
*/

void		op_substract(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	get_params(vm, champ);
	resolve_params(vm, champ, champ->params, 3);
	p = champ->params;
	champ->reg[check_reg(champ->params->p3)] = champ->params->p1
		- champ->params->p2;
	champ->carry = 1;
}
