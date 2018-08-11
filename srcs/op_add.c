/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:12:20 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/11 18:20:47 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take three registries, add up the first two and store the result in third.
*/

void		op_add(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	resolve_params(vm, champ, champ->params, 3);
	p = champ->params;
	champ->reg[check_reg(champ->params->p3)] = champ->params->p1
		+ champ->params->p2;
	champ->carry = 1;
}
