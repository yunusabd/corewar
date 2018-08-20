/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 14:52:01 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 01:50:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_champ		*find_champ(t_vm *vm, int nb)
{
	t_champ	*tmp;

	tmp = vm->champs;
	if (vm->last_live && tmp->number == vm->last_live->number)
		return (vm->last_live);
	if (vm->last_live && tmp->number == -(vm->last_live->number))
		return (tmp);
	while (tmp)
	{
		if (nb == tmp->number)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
