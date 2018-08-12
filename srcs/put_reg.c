/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:25:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/12 20:24:22 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		chk_reg(t_vm *vm, t_champ *champ, int reg)
{
	if (reg < 1 || reg > REG_NUMBER)
		reg += 0;
		//TODO kill process
	else
		return ;
}

void		put_reg(t_vm *vm, t_champ *champ, int reg_no, intmax_t value)
{
	intmax_t		s;

	chk_reg(vm, champ, reg_no - 1);
	s = ft_power(2, REG_SIZE * 8) - 1;
	champ->reg[reg_no - 1] = value & s;
}
