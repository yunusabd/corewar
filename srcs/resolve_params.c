/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:51:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 21:34:23 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	If a parameter is a register according to the encoding byte, get the value
**	from the corresponding register, after confirming that it exists.
*/

void	resolve_params(t_vm *vm, t_champ *champ, t_params *param)
{
	if ((champ->encoding_byte & 192) == 64)
		param->p1 = champ->reg[check_reg(param->p1)];
	if ((champ->encoding_byte & 48) == 16)
		param->p2 = champ->reg[check_reg(param->p2)];
	if ((champ->encoding_byte & 12) == 4)
		param->p3 = champ->reg[check_reg(param->p3)];
}
