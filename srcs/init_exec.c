/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 01:31:20 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/03 01:37:13 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_exec	*init_exec(t_vm *vm)
{
	t_exec	*new;

	if (!(new = (t_exec*)malloc(sizeof(t_exec))))
		error_exit(vm, "Malloc fail in init_exec");
	ft_bzero(new, sizeof(t_exec));
	return (new);
}
