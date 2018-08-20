/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:25:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 00:46:24 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		chk_reg(t_vm *vm, t_champ *champ, int reg)
{
	if (reg < 0 || reg > REG_NUMBER - 1)
		kill_process(vm, champ);
	else
		return ;
}

void			put_reg(t_vm *vm, t_champ *champ, int reg_no, intmax_t value)
{
	intmax_t		mask;

	chk_reg(vm, champ, reg_no - 1);
	mask = ft_power(2, REG_SIZE * 8) - 1;
	champ->reg[reg_no - 1] = value & mask;
}
