/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:07:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 14:34:32 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take a registry, and two indexes (potentially registries) add the two
**	indexes, and use this result as an address where the value of the first
**	parameter will be copied.
*/

void			op_sti(t_vm *vm, t_champ *champ)
{
	int			i;
	intmax_t	res;
	int			tmp;

	resolve_params(champ, champ->params, 1 + 2 + 4);
	res = champ->params->p2 + champ->params->p3;
	tmp = champ->pc;
	printf("%jd %jd %jd\n", champ->params->p1, champ->params->p2, champ->params->p3);
	exit(1);
	move_pc(&tmp, (res % IDX_MOD) - 1);
	i = 0;
	while (i < REG_SIZE)
	{
		move_pc(&tmp, -1);
		vm->memory[tmp] = (champ->params->p1 >> (8 * i) & 0xFF);
		i++;
	}
}
