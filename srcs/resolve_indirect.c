/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_indirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 04:31:37 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 18:06:27 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	get_ind(t_vm *vm, t_champ *champ, intmax_t *ptr)
{
	int		tmp;

	tmp = champ->pc;
	if (champ->opcode == 13 || champ->opcode == 14 || champ->opcode == 15
			|| champ->opcode == 10 || champ->opcode == 11)
		move_pc(&tmp, ((int)*ptr));
	else
		move_pc(&tmp, ((int)*ptr) % IDX_MOD);
	*ptr = add_next_octets(vm, &tmp, REG_SIZE);
}

/*
**	If a parameter is indirect according to the encoding byte, get the value
**	from the corresponding position.
**	Set first bit of n for first param, second bit for second param etc.
*/

void		resolve_indirect(t_vm *vm, t_champ *champ, int n)
{
	if (n & 1 && (champ->encoding_byte & 192) == 192)
		get_ind(vm, champ, &(champ->params->p1));
	if (n & 2 && (champ->encoding_byte & 48) == 48)
		get_ind(vm, champ, &(champ->params->p2));
	if (n & 4 && (champ->encoding_byte & 12) == 12)
		get_ind(vm, champ, &(champ->params->p3));
}
