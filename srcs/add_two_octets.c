/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_two_octets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:04:33 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/11 20:09:52 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Takes an address in memory and adds the next octet(s) to it.
*/

int		add_two_octets(t_vm *vm, int pc)
{
	int	res;

	res = vm->memory[pc];
	res = res << 8;
	move_pc(&pc, 1);
	res |= vm->memory[pc];
	return (res);
}

int		add_next_octets(t_vm *vm, int *pc, int n)
{
	int	res;
	int	i;

	res = vm->memory[*pc];
	n--;
	i = 0;
	while (i < n)
	{
		res = res << 8;
		move_pc(pc, 1);
		res |= vm->memory[*pc];
		i++;
	}
	move_pc(pc, 1);
	return (res);
}
