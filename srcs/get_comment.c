/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 00:01:32 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/10 16:26:12 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_comment(t_vm *vm, t_champ *champ)
{
	int		i;
	t_byte	*tmp;
	t_byte	*start;

	i = 0;
	tmp = champ->bytes;
	while (tmp && i++ < PROG_NAME_LENGTH + 8 + 4)
		tmp = tmp->next;
	start = tmp;
	i = 0;
	while (tmp && tmp->byte && i++ < COMMENT_LENGTH)
		tmp = tmp->next;
	if (!(champ->comment = ft_strnew(i)))
		error_exit(vm, "Malloc fail in get_comment");
	i = 0;
	tmp = start;
	while (tmp && tmp->byte && i < PROG_NAME_LENGTH)
	{
		champ->comment[i++] = tmp->byte;
		tmp = tmp->next;
	}
}
