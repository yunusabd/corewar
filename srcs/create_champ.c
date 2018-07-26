/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:57:21 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 15:54:22 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*tmp;

	tmp = vm->champs;
	if (!(tmp))
		vm->champs = champ;
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = champ;
	}
}

t_champ	*create_champ(t_vm *vm)
{
	t_champ	*new;

	if (!(new = (t_champ*)malloc(sizeof(t_champ))))
		error_exit(vm, "Malloc fail in create_champ");
	ft_bzero(new, sizeof(t_champ));
	return (new);
}
