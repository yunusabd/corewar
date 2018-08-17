/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:47:04 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/17 16:45:25 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	TODO: FIX!!!!
*/

void	add_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*tmp;

	if ((vm->champs))
	{
		tmp = vm->champs;
		while (tmp && tmp->next && tmp->next->number > champ->number)
			tmp = tmp->next;
		if (tmp->next)
			champ->next = tmp->next->next;
		tmp->next = champ;
	}
	vm->champs = champ;
}
