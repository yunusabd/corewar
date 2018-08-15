/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:13:54 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/15 17:24:39 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_st(t_vm *vm, t_champ *champ)
{
	int		i;
	int		tmp;

	resolve_params(vm, champ, champ->params, 1);
	tmp = champ->pc;
	if ((champ->encoding_byte & 48) == 16)
	    put_reg(vm, champ, champ->params->p2, champ->reg[check_reg(champ->params->p1)]);
	else
	{	
		move_pc(&(tmp), (champ->params->p2 + REG_SIZE - 1) % IDX_MOD);
		i = 0;
		while (i < REG_SIZE)
		{
			move_pc(&(tmp), -1);
			vm->memory[tmp] = ((champ->params->p1 >> 8 * i) & 0xFF);
			i++;
		}
	}
}
