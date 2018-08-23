/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 23:59:07 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/28 23:59:20 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_name(t_vm *vm, t_champ *champ)
{
	int		i;
	t_byte	*tmp;
	t_byte	*start;

	i = 0;
	tmp = champ->bytes;
	while (tmp && i++ < 4)
		tmp = tmp->next;
	start = tmp;
	i = 0;
	while (tmp && tmp->byte && i++ < PROG_NAME_LENGTH)
		tmp = tmp->next;
	if (!(champ->name = ft_strnew(i)))
		error_exit(vm, "Malloc fail in get_name");
	i = 0;
	tmp = start;
	while (tmp && tmp->byte && i < PROG_NAME_LENGTH)
	{
		champ->name[i++] = tmp->byte;
		tmp = tmp->next;
	}
}
