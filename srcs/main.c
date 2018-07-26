/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 20:37:51 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	The magic number gets casted as an int. 
**	We copy 4 chars from the read buffer as an unsigned char * into the dup var.
**	Starting from the rightmost of the 4 chars, we compare the 8 bits of each
**	char to 8 bits of the int with the magic number, while shifting both.
*/

void	check_magic_number(t_vm *vm, t_champ *champ, char *buff)
{
	unsigned char	*dup;
	int				magic;
	int				j;
	int				i;

	dup = (unsigned char*)ft_strndup_len(buff, 4);
	magic = (COREWAR_EXEC_MAGIC);
	i = 3;
	while (i >= 0)
	{
		j = 8;
		while (j--)
		{
			if (!((magic & 1) == (dup[i] & 1)))
				error_exit(vm, "Wrong magic number");
			magic = magic >> 1;
			dup[i] = dup[i] >> 1;
		}
		i--;
	}
	champ->magic = 1;
	free(dup);
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
			if (champ->magic == 0 && read_bytes > 3)
				check_magic_number(vm, champ, buffer);
			if (champ->name == NULL)
				get_name(champ, buffer);
		}
		add_champ(vm, champ);
		champ = NULL;
	}
	printf("NAME: %s\n", vm->champs->name);
//	printf("NAME: %s\n", vm->champs->next->name);
	return (0);
}
