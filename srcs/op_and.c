/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:49:52 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 22:05:35 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_and(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	get_params(vm, champ);
	p = champ->params;
	printf("p1: %d, p2: %d, p3: %d\n", p->p1, p->p2, p->p3);
	resolve_params(vm, champ, champ->params, 3);
	p = champ->params;
	printf("p1: %d, p2: %d, p3: %d\n", p->p1, p->p2, p->p3);
	champ->reg[check_reg(p->p3)] = p->p1 & p->p2;
	printf("Wrote result [%d] into reg [%d]\n", p->p3, p->p1 & p->p2);
}
