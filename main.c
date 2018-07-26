/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 11:54:22 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_magic_number(char *buff)
{
	printf("MAGIC: %x\n", COREWAR_EXEC_MAGIC);
	printf("MAGIC: %d\n", buff[4]);
	if (*buff == (COREWAR_EXEC_MAGIC))
		printf("It's the same!\n");
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	int		read_bytes;
	char	buffer[READ_BUFF_SIZE];
	char	*ptr;
	t_vm	*vm;

	vm = create_vm(ac, av);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		exit(0);
/*
**	add error_exit function.
*/
	read(fd, buffer, READ_BUFF_SIZE);
	check_magic_number(buffer);
//	write(1, "First read: [", 13);
	ptr = buffer;
	ptr += 4;
	write(1, ptr, READ_BUFF_SIZE);
	return (0);
}
