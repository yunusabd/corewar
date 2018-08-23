/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_magic_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 21:07:33 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 21:22:56 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	The magic number gets casted as an int.
**	We copy 4 chars from the read buffer as an unsigned char* into the dup var.
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
