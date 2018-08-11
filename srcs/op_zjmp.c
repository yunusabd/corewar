/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:44:52 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/11 21:17:21 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_zjmp(t_vm *vm, t_champ *champ)
{
	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	get_direct(vm, champ, &(champ->params->p1));
	if (champ->carry)
		champ->pc_tmp = (champ->pc + champ->params->p1 & 0xFFFF) % IDX_MOD - 1;
}
