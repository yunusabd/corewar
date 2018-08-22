/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judgement_day.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:54:04 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 12:45:42 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

void	judgement_day(t_vm *vm)
{
	if (!(vm->flags & MATRIX))
	{
		if (vm->last_live)
			ft_printf("Player %d (%s) won\n", vm->last_live->number,
				vm->last_live->name);
		else
			ft_printf("There is no winner. "\
					"Or, in some sense, everybody wins :)\n");
	}
}
