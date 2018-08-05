/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 22:43:07 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 19:04:20 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_reg(t_vm *vm, int pc)
{
	return (vm->memory[pc]);
}

void	get_params(t_vm *vm, t_champ *champ)
{
	int		i;
	int		*j;

	champ->exec = init_exec(vm);
	champ->pc_tmp = champ->pc;
	move_pc(&(champ->pc_tmp), 1);
	i = (sizeof(char) * 8);
	j = &(champ->exec->p1);
	while (i -= 2 > 0)
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
			move_pc(&(champ->pc_tmp), 2);
		j++;
	}
}
