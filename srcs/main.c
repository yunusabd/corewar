/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/16 19:15:16 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	t_vm	*vm;
	int		i;

	vm = create_vm(ac, av);
	while (ac-- > 1)
		reader(vm, ac, av[ac]);
	load_processes(vm);
	printf(CLEAR);
	i = 0;
	while (vm->cycles++ < 18000)
	{
		if ((vm->cycles % CYCLE_TO_DIE) == 0)
			cycle_check(vm);
		run_champs(vm);
	 	if (i < vm->cycles && (vm->cycles % 1) == 0)
			dump_handler(vm);
	}
	return (0);
}
