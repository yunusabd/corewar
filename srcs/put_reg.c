/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:25:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 12:38:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		chk_reg(t_vm *vm, t_champ *champ, int reg)
{
	if (reg < 1 || reg > REG_NUMBER)
		return (0);
	else
		return (1);
	return (0);
	kill_process(vm, champ);
}

void			put_reg(t_vm *vm, t_champ *champ, int reg_no, intmax_t value)
{
	if (chk_reg(vm, champ, reg_no) == 0)
		return ;
	champ->reg[reg_no - 1] = (int)value;
}
