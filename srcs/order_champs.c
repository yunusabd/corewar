/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:49:05 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 18:55:13 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			print_champs(t_vm *vm)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		ft_printf("Champ %d: %s\n", tmp->number, tmp->name);
		tmp = tmp->next;
	}
}

/*
**	Bubble sort the champions.
*/

void			order_champs(t_vm *vm)
{
	t_champ	*tmp;
	t_champ	*tmp2;
	t_champ	*prev;

	tmp = vm->champs;
	prev = vm->champs;
	while (tmp)
	{
		if (tmp && tmp->next && tmp->number < tmp->next->number)
		{
			tmp2 = tmp->next->next;
			tmp->next->next = tmp;
			if (tmp == vm->champs)
				vm->champs = tmp->next;
			else
				prev->next = tmp->next;
			tmp->next = tmp2;
			tmp = vm->champs;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
