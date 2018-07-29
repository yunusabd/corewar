/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:33:55 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/29 20:36:33 by yabdulha         ###   ########.fr       */
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
		k = 0;
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
