/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:47:04 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 17:45:31 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_champ(t_vm *vm, t_champ *champ)
{
	if ((vm->champs))
		champ->next = vm->champs;
	vm->champs = champ;
}

void	add_process(t_vm *vm, t_champ *champ)
{
	if ((vm->champs))
		champ->next = vm->champs;
	vm->champs = champ;
}
