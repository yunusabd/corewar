/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:41:34 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/07 19:35:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	insert_champ(t_vm *vm, t_champ *champ)
{
	int	i;

	i = 0;
	while (i < champ->size)
	{
		printf("%.2x ", (unsigned char)champ->data[i]);
		vm->memory[champ->pc + i] = (unsigned char)champ->data[i];
		i++;
	}
	usleep(100000);
}

void	op_fork(t_vm *vm, t_champ *champ)
{
	t_champ	*new;

	if (!(new = (t_champ*)malloc(sizeof(t_champ))))
		error_exit(vm, "Malloc fail in op_fork");
	if (!(new = ft_memcpy(new, champ, sizeof(champ))))
		error_exit(vm, "Malloc fail in op_fork");
	new->data = ft_strdup(champ->data);
	champ->params = init_params(vm);
	champ->pc_tmp = champ->pc;
	get_direct(vm, champ, &(champ->params->p1));
    champ->cycles = g_op_tab[champ->opcode - 1].cycles;
	move_pc(&(new->pc), champ->params->p1 % IDX_MOD);
	printf("new position: %d\n", new->pc);
	printf("data: %d\n", new->data[0]);
	insert_champ(vm, new);
	add_champ(vm, new);
	printf("PLAYER %d FORKED\n", champ->params->p1);
}
