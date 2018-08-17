/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:56:13 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/16 22:16:01 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_vm	*create_vm(int ac, char **av)
{
	t_vm	*new;

	if (!(new = (t_vm*)malloc(sizeof(t_vm))))
		error_exit(NULL, "Malloc fail in create_vm");
	ft_bzero(new, sizeof(t_vm));
	new->ac = ac;
	new->av = av;
	new->cycles_to_die = CYCLE_TO_DIE;
	return (new);
}
