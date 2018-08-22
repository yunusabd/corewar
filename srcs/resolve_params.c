/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:51:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 19:28:45 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	If a parameter is a register according to the encoding byte, get the value
**	from the corresponding register, after confirming that it exists.
**	Set first bit of n for first param, second bit for second param etc.
*/

int	resolve_params(t_champ *champ, t_params *param, int n)
{
	int		reg;

	if (n & 1 && (champ->encoding_byte & 192) == 64)
	{
		reg = check_reg(param->p1);
		(reg) ? param->p1 = (int)champ->reg[reg - 1] : 0;
		if (!reg)
			return (0);
	}
	if (n & 2 && (champ->encoding_byte & 48) == 16)
	{
		reg = check_reg(param->p2);
		(reg) ? param->p2 = (int)champ->reg[reg - 1] : 0;
		if (!reg)
			return (0);
	}
	if (n & 4 && (champ->encoding_byte & 12) == 4)
	{
		reg = check_reg(param->p3);
		(reg) ? param->p3 = (int)champ->reg[reg - 1] : 0;
		if (!reg)
			return (0);
	}
	return (1);
}
