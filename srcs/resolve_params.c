/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:51:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 13:37:10 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	If a parameter is a register according to the encoding byte, get the value
**	from the corresponding register, after confirming that it exists.
**	Set first bit of n for first param, second bit for second param etc.
*/

void	resolve_params(t_champ *champ, t_params *param, int n)
{
	if (n & 1 && (champ->encoding_byte & 192) == 64)
		param->p1 = (int)champ->reg[check_reg(param->p1 - 1)];
	if (n & 2 && (champ->encoding_byte & 48) == 16)
		param->p2 = (int)champ->reg[check_reg(param->p2 - 1)];
	if (n & 4 && (champ->encoding_byte & 12) == 4)
		param->p3 = (int)champ->reg[check_reg(param->p3 - 1)];
}
