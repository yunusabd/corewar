/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:06:23 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 19:53:15 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	free_bytes(t_vm *vm)
{
	t_byte	*tmp;

	while (vm->champs->bytes)
	{
		tmp = vm->champs->bytes->next;
		free(vm->champs->bytes);
		vm->champs->bytes = tmp;
	}
}

static void	free_champs(t_vm *vm)
{
	t_champ	*tmp;

	while (vm->champs)
	{
		tmp = vm->champs->next;
		free(vm->champs);
		vm->champs = tmp;
	}
}

void		error_exit(t_vm *vm, char *msg)
{
	t_champ *tmp;

	while (vm->champs)
	{
		tmp = vm->champs->next;
		free(vm->champs->name);
		free(vm->champs->params);
		free(vm->champs->data);
		free(vm->champs->comment);
		free_bytes(vm);
		ft_bzero(vm->champs, sizeof(t_champ));
		vm->champs->next = tmp;
		vm->champs = tmp;
	}
	free_champs(vm);
	free(vm);
	if (ft_strcmp(msg, "OK") == 0)
		exit(0);
	printf("%s\n", msg);
	exit(1);
}
