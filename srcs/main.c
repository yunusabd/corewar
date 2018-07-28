/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/29 00:10:56 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	int		read_bytes;
	char	buffer[READ_BUFF_SIZE];
	t_vm	*vm;
	t_champ	*champ;

	vm = create_vm(ac, av);
	while (ac-- > 1)
	{
		reader(vm, ac, av[ac]);
	/*
		if ((fd = open(av[--ac], O_RDONLY)) < 0)
			error_exit(vm, "Can't open file");
	 	champ = create_champ(vm);
		champ->filename = av[ac];
		while ((read_bytes = read(fd, buffer, READ_BUFF_SIZE)) > 0)
		{
			if (champ->magic == 0 && read_bytes > 3)
				check_magic_number(vm, champ, buffer);
			if (champ->name == NULL)
				get_name(champ, buffer);
		}
		add_champ(vm, champ);
		champ = NULL;
	*/
	}
/*	
 	while (vm->champs)
	{
		printf("NAME: %s\n", vm->champs->name);
		printf("FILENAME: %s\n", vm->champs->filename);
		vm->champs = vm->champs->next;
	}
*/
	return (0);
}
