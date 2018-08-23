/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 19:01:35 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/11 21:21:39 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Preliminary checks before parsing.
*/

int		error_check(t_vm *vm)
{
	if (READ_BUFF_SIZE < 4)
		error_exit(vm, "READ_BUFF_SIZE needs to be 4 or greater");
	if (READ_BUFF_SIZE > 9999)
		error_exit(vm, "READ_BUFF_SIZE too big");
}
