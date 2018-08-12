/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:59:15 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/12 16:23:39 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_ldi(t_vm *vm, t_champ *champ)
{
	intmax_t	res;

	resolve_params(vm, champ, champ->params, 1 + 2);
	move_pc(&(champ->pc_tmp), champ->params->p1 + champ->params->p2);
	res = add_next_octets(vm, &(champ->pc_tmp), REG_SIZE);
	put_reg(vm, champ, champ->params->p3, res);
	printf("\nPUT %ld in REG %d\n", res, champ->params->p3);
	exit(1);
}
