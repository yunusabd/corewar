/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:12:20 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/11 21:55:13 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Take three registries, add up the first two and store the result in third.
*/

void		op_add(t_vm *vm, t_champ *champ)
{
	t_params	*p;

	resolve_params(vm, champ, champ->params, 3);
	p = champ->params;
	put_reg(vm, champ, p->p3, p->p1 + p->p2);
	champ->carry = 1;
}
