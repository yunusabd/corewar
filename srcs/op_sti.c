/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:07:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/12 21:21:30 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		resolve_number(int nb)
{
	printf("NB: %d\n", nb);
//	nb = (~(nb) & 0xFFFF);
	nb = (signed short)nb;
	printf("NB: %d\n", nb);
	return (nb);
}

/*
**	Take a registry, and two indexes (potentially registries) add the two
**	indexes, and use this result as an address where the value of the first
**	parameter will be copied.
*/

void			op_sti(t_vm *vm, t_champ *champ)
{
	int		i;
	int		res;
	int		tmp;

	tmp = champ->pc_tmp;
	resolve_params(vm, champ, champ->params, 7);
	champ->params->p2 += champ->params->p3;
	champ->pc_tmp = champ->pc;
	res = resolve_number(champ->params->p2 + champ->params->p3);
	move_pc(&(champ->pc_tmp), res + REG_SIZE - 1);
	printf("p1: %d\n", champ->params->p1);
	printf("res: %d\n", res);
	i = 0;
	while (i < REG_SIZE)
	{
		move_pc(&(champ->pc_tmp), -1);
		vm->memory[champ->pc_tmp] = (champ->params->p1 >> (8 * i)) & 255;
		printf("\n%d\n", vm->memory[champ->pc_tmp] = (champ->params->p1 >> (8 * i)) & 255);
		i++;
	}
	if (champ->params->p2 + champ->params->p3 == 0xFFD3)
		exit(1);
	champ->pc_tmp = tmp;
}
