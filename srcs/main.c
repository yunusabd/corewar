/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/05 22:03:07 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	t_vm	*vm;

	vm = create_vm(ac, av);
	while (ac-- > 1)
		reader(vm, ac, av[ac]);
	load_processes(vm);
	dump_memory(vm);
	run_champs(vm);
	dump_memory(vm);
	run_champs(vm);
	dump_memory(vm);
	return (0);
}
