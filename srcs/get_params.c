/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:49:42 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/15 21:48:10 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Get a register value, stored in a single octet.
*/

void			get_reg(t_vm *vm, t_champ *champ, intmax_t *j)
{
	printf("get reg\n");
	*j = (unsigned char)vm->memory[champ->pc_tmp];
	move_pc(&(champ->pc_tmp), 1);
}

/*
**	Check the op_tab if the direct parameter is half or full size and
**	read octets accordingly.
*/

void			get_direct(t_vm *vm, t_champ *champ, intmax_t *j)
{
	printf("get direct\n");
	if ((g_op_tab[champ->opcode - 1].half_size) == 1)
		*j = (short)add_next_octets(vm, &(champ->pc_tmp), DIR_SIZE / 2);
	else
		*j = (int)add_next_octets(vm, &(champ->pc_tmp), DIR_SIZE);
	printf("j: %lld\n", *j);
}

/*
**	Gets IND_SIZE octets from the speficied position.
*/

void			get_indirect(t_vm *vm, t_champ *champ, intmax_t *j)
{
	printf("get indirect\n");
	*j = (short)add_next_octets(vm, &(champ->pc_tmp), IND_SIZE);
}

/*
**	Read the parameters according to the encoding byte. If it is a register,
**	read one octet, for direct or indirect read two.
**	For opcodes 9, 10, 11, 12, 14, 15 direct param is 2 octets, otherwise 4.
*/

void			get_params(t_vm *vm, t_champ *champ)
{
	int			i;
	intmax_t	*j;

	champ->params = init_params(vm);
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
