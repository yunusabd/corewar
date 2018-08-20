/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:47:04 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/20 18:39:35 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*tmp;

	if ((vm->champs))
	{
		printf("if\n");
		tmp = vm->champs;
		while (tmp && tmp->next)
			tmp = tmp->next;
		printf("add %s after: %s\n", champ->name, tmp->name);
		tmp->next = champ;
	}
	else
	{
		vm->champs = champ;
		printf("first: %s\n", champ->name);
	}
}

void	add_process(t_vm *vm, t_champ *champ)
{
	if ((vm->champs))
		champ->next = vm->champs;
	vm->champs = champ;
}
