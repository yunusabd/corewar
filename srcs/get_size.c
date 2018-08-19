/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 00:00:33 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/10 16:31:43 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

void	get_size(t_vm *vm, t_champ *champ)
{
	int		res;
	int		i;
	t_byte	*tmp;

	res = 0;
	i = 0;
	tmp = champ->bytes;
	while (tmp && i++ < PROG_NAME_LENGTH + 8)
		tmp = tmp->next;
	i = 0;
	while (tmp && i++ < 4)
	{
		res = res << 8;
		res |= (unsigned char)tmp->byte;
		tmp = tmp->next;
	}
	champ->size = res;
	if (!(vm->flags & MATRIX))
		printf("\n\nSIZE: %d\n", res);
}
