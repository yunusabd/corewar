/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 02:20:55 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 20:25:02 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Write the value in the first arg to the register specified
**	in the second arg.
*/

void	op_lld(t_vm *vm, t_champ *champ)
{
	resolve_indirect(vm, champ, 1);
	put_reg(vm, champ, champ->params->p2, champ->params->p1);
	if (champ->params->p1 == 0)
		champ->carry = 1;
	else
		champ->carry = 0;
}
