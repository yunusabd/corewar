/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 16:00:59 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_magic_number(t_champ *champ, char *buff)
{
	printf("MAGIC: %x\n", COREWAR_EXEC_MAGIC);
	if (buff[0] == 0)
		printf("1 It's the same!\n");
	if ((unsigned char)buff[1] == 234)
		printf("2 It's the same!\n");
	if ((unsigned char)buff[2] == 131)
		printf("3 It's the same!\n");
	if ((unsigned char)buff[3] == 243)
		printf("4 It's the same!\n");
	champ->magic = 1;
	return (1);
}

int		get_name(t_champ *champ, char *buff)
{
	champ->name = ft_strndup(buff + 4, PROG_NAME_LENGTH);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	int		read_bytes;
	char	buffer[READ_BUFF_SIZE];
	t_vm	*vm;
	t_champ	*champ;

	vm = create_vm(ac, av);
	while (ac > 1)
	{
		if ((fd = open(av[--ac], O_RDONLY)) < 0)
			error_exit(vm, "Can't open file");
		champ = create_champ(vm);
		while ((read_bytes = read(fd, buffer, READ_BUFF_SIZE)) > 0)
		{
			if (champ->magic == 0)
				check_magic_number(champ, buffer);
			if (champ->name == NULL)
				get_name(champ, buffer);
		}
		add_champ(vm, champ);
		printf("NAME: %s\n", vm->champs->name);
	}
	return (0);
}
