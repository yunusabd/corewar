/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:13:54 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/11 21:52:27 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_st(t_vm *vm, t_champ *champ)
{
	int		i;

	resolve_params(vm, champ, champ->params, 1);
	if ((champ->encoding_byte & 48) == 16)
	    put_reg(vm, champ, champ->params->p2, champ->params->p1);
	else
	{	
		champ->pc_tmp = champ->pc;
		move_pc(&(champ->pc_tmp), (champ->params->p2 + REG_SIZE - 1) % IDX_MOD);
		i = 0;
		while (i < REG_SIZE)
		{
			move_pc(&(champ->pc_tmp), -1);
			vm->memory[champ->pc_tmp] = ((champ->params->p1 >> 8 * i) & 255);
			i++;
		}
	}
	champ->pc_tmp = champ->pc;
}
