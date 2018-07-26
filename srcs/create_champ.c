/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:57:21 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 21:18:54 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_champ(t_vm *vm, t_champ *champ)
{
	if ((vm->champs))
		champ->next = vm->champs;
	vm->champs = champ;
}

t_champ	*create_champ(t_vm *vm)
{
	t_champ	*new;

	if (!(new = (t_champ*)malloc(sizeof(t_champ))))
		error_exit(vm, "Malloc fail in create_champ");
	ft_bzero(new, sizeof(t_champ));
	return (new);
}
