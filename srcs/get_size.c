/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 00:00:33 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/22 20:29:11 by yabdulha         ###   ########.fr       */
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
	if (res > CHAMP_MAX_SIZE || res < 0)
		error_exit(vm, "Invalid champion size");
	champ->size = res;
}
