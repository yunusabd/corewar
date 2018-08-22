/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:51:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 01:53:58 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

/*
**	Write the value in the first arg to the register
**	specified in the second arg.
*/

void	op_ld(t_vm *vm, t_champ *champ)
{
	resolve_indirect(vm, champ, 1);
	put_reg(vm, champ, champ->params->p2, champ->params->p1);
	printf("put %jd in reg %jd\n", champ->params->p1, champ->params->p2);
	if (champ->params->p1 == 0)
		champ->carry = 1;
	else
		champ->carry = 0;
}
