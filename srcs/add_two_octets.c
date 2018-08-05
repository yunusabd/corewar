/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_two_octets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:04:33 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 20:05:14 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Takes an address in memory and adds the next octet to it.
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
