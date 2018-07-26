/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:56:13 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 11:49:05 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <string.h>

t_vm	*create_vm(int ac, char **av)
{
	t_vm	*new;

	if (!(new = (t_vm*)malloc(sizeof(t_vm))))
		exit(1);
	// TODO error exit function
	bzero(new, sizeof(new));
	new->ac = ac;
	new->av = av;
	return (new);
}
