/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:25:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/12 13:27:32 by yabdulha         ###   ########.fr       */
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

void		put_reg(t_vm *vm, t_champ *champ, int reg_no, int value)
{
	intmax_t		s;

	chk_reg(vm, champ, reg_no);
	s = ft_power(2, REG_SIZE * 8) - 1;
	s = s >> (sizeof(s) * 8);
	printf("result: %x\n", value & s);
	champ->reg[reg_no] = value & s;
}
