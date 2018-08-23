/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:47:16 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 20:47:32 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_params	*init_params(t_vm *vm)
{
	t_params	*new;

	if (!(new = (t_params*)malloc(sizeof(t_params))))
		error_exit(vm, "Malloc fail in init_params");
	ft_bzero(new, sizeof(t_params));
	return (new);
}
