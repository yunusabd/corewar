/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:51:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/12 21:07:34 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Write the value in the first arg to the register specified in the second arg.
*/

void	op_ld(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	p = champ->params;
	resolve_params(vm, champ, champ->params, 1);
    put_reg(vm, champ, champ->params->p2, champ->params->p1);
	if (champ->params->p1 == 0)
		champ->carry = 1;
	else
		champ->carry = 0;
	printf("p1: %d\n", champ->params->p1);
}
