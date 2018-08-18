/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 14:52:01 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/18 14:54:40 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_champ		*find_champ(t_vm *vm, int nb)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		if (nb == tmp->number)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
