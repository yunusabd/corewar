/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:49:42 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 21:49:47 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		get_reg(t_vm *vm, int pc)
{
	return (vm->memory[pc]);
}

/*
**	Read the parameters according to the encoding byte. If it is a register,
**	read one octet, for direct or indirect read two octets.
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
		if (((champ->encoding_byte >> i) & 3) > 1)
		{
			*j = add_two_octets(vm, champ->pc_tmp);
			move_pc(&(champ->pc_tmp), 2);
		}
		else if (((champ->encoding_byte >> i) & 3) == 1)
		{
			*j = get_reg(vm, champ->pc_tmp);
			move_pc(&(champ->pc_tmp), 1);
		}
		else
			break;
		i -= 2;
		j++;
	}
}
