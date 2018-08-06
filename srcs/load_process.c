/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:33:55 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/06 19:41:39 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		load_processes(t_vm *vm)
{
	int		i;
	int		j;
	int		k;
	t_champ	*tmp;

	tmp = vm->champs;
	i = 0;
	j = 0;
	while (tmp)
	{
		i = (MEM_SIZE / (vm->players)) * j;
		tmp->pc = i;
		k = 0;
		tmp->start = i;
		while (k < tmp->size)
		{
			vm->memory[i] = (unsigned char)tmp->data[k];
			i++;
			k++;
		}
		j++;
		tmp = tmp->next;
	}
}
