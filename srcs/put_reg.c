/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:25:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/15 04:27:03 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				resolve_number(int nb)
{
//	if (nb & (1 << (REG_SIZE * 8 - 1)))
//		nb = -(~nb + 1);
	return (nb & (ft_power(2, REG_SIZE * 8) - 1));
}

static void		chk_reg(t_vm *vm, t_champ *champ, int reg)
{
	if (reg < 1 || reg > REG_NUMBER)
		reg += 0;
		//TODO kill process
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
