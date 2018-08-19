/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:51:25 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/19 16:56:00 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		get_data(t_vm *vm, t_champ *champ)
{
	int		i;
	t_byte	*tmp;

	i = 0;
	tmp = champ->bytes;
	while (tmp && i++ < PROG_NAME_LENGTH + COMMENT_LENGTH + 8 + 4 + 4)
		tmp = tmp->next;
	if (!(champ->data = ft_strnew(champ->size)))
		error_exit(vm, "Malloc fail in get_comment");
	i = 0;
	while (tmp && i < champ->size)
	{
		champ->data[i++] = tmp->byte;
		tmp = tmp->next;
	}
}

int				parse_bytes(t_vm *vm, t_champ *champ)
{
	if (!(champ->bytes))
		error_exit(vm, "Empty champ");
	get_size(champ);
	get_name(vm, champ);
	get_comment(vm, champ);
	get_data(vm, champ);
	return (1);
}
