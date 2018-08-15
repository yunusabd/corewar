/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/15 15:23:54 by yabdulha         ###   ########.fr       */
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
	while (vm->cycles++ < 14000)
	{
		run_champs(vm);
		if (i < vm->cycles)
			dump_handler(vm);
	}
	return (0);
}
