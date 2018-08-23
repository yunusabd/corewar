/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:06:23 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 23:47:41 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	free_bytes(t_champ *champ)
{
	t_byte	*tmp;

	while (champ->bytes)
	{
		tmp = champ->bytes->next;
		free(champ->bytes);
		champ->bytes = tmp;
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

	tmp = vm->champs;
	while (tmp)
	{
		free(tmp->name);
		free(tmp->params);
		free(tmp->data);
		free(tmp->comment);
		free_bytes(tmp);
		tmp = tmp->next;
	}
	free_champs(vm);
	free(vm);
	ft_printf(SHOW_CURSOR);
	if (ft_strcmp(msg, "OK") == 0)
		exit(0);
	ft_printf("%s\n", msg);
	exit(1);
}
