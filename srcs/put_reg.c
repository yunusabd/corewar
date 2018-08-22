/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:25:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 01:54:49 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		chk_reg(t_vm *vm, t_champ *champ, int reg)
{
	if (reg < 0 || reg > REG_NUMBER)
	{
		printf("put %jd in reg %jd\n", champ->params->p1, champ->params->p2);
		kill_process(vm, champ);
		printf("wrong reg: %d\n", champ->opcode);
		exit(1);
	}
	else
		return (1);
	return (0);
}

void			put_reg(t_vm *vm, t_champ *champ, int reg_no, intmax_t value)
{
	if (chk_reg(vm, champ, reg_no - 1) == 0)
		return ;
	champ->reg[reg_no - 1] = (int)value;
}
