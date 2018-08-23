/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 00:53:44 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 23:33:40 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

void	op_aff(t_vm *vm, t_champ *champ)
{
	resolve_params(champ, champ->params, 1);
	champ->params->p1 %= 256;
	vm += 0;
	if (!(vm->flags & MATRIX))
		ft_printf("aff: %c\n", (char)champ->params->p1);
}
