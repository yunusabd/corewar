/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:49:42 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/06 15:43:15 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			get_reg(t_vm *vm, t_champ *champ, int *j)
{
	*j = vm->memory[champ->pc_tmp];
	move_pc(&(champ->pc_tmp), 1);
}

/*
**	Check the op_tab if the direct parameter is 4 or 2 octets.
*/

void			get_direct(t_vm *vm, t_champ *champ, int *j)
{
	if ((g_op_tab[champ->opcode - 1].half_size) == 1)
	{
		*j = add_two_octets(vm, champ->pc_tmp);
		move_pc(&(champ->pc_tmp), 2);
	}
	else
	{
		*j = add_two_octets(vm, champ->pc_tmp);
		move_pc(&(champ->pc_tmp), 2);
		*j = add_two_octets(vm, champ->pc_tmp);
		move_pc(&(champ->pc_tmp), 2);
	}
}

void			get_indirect(t_vm *vm, t_champ *champ, int *j)
{
	*j = add_two_octets(vm, champ->pc_tmp);
	move_pc(&(champ->pc_tmp), 2);
}

/*
**	Read the parameters according to the encoding byte. If it is a register,
**	read one octet, for direct or indirect read two octets.
**	For opcodes 9, 10, 11, 12, 14, 15 direct param is 2 octets, otherwise 4.
*/

void			get_params(t_vm *vm, t_champ *champ)
{
	int		i;
	int		*j;

	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	move_pc(&(champ->pc_tmp), 1);
	i = (sizeof(char) * (8 - 2));
	j = &(champ->params->p1);
	while (i > 0)
	{
		if (((champ->encoding_byte >> i) & 3) == 2)
			get_direct(vm, champ, j);
		else if (((champ->encoding_byte >> i) & 3) == 3)
			get_indirect(vm, champ, j);
		else if (((champ->encoding_byte >> i) & 3) == 1)
			get_reg(vm, champ, j);
		else
			break;
		i -= 2;
		j++;
	}
}
