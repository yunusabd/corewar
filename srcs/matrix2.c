/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:30:08 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/22 18:56:48 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static int	check_players2(t_vm *vm)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < MAX_PLAYERS + 1)
	{
		if (vm->processes_counter[i] > 0)
			counter++;
		i++;
	}
	return (counter);
}

void		fl_write_compr(int l, t_vm *vm, int fd, int val)
{
	fl_write_data_num(l, vm, fd);
	write(fd, ", ", 2);
	fl_write_data_num(val, vm, fd);
}

void		fl_write_first(int val, t_vm *vm, int fd, int l)
{
	fl_write_data_num(val, vm, fd);
	if (l < MEM_SIZE - 1)
		write(fd, ", ", 2);
}

void		fl_matrix_end(t_vm *vm, int fd, int **memory2)
{
	char *winner;

	if (((vm->cycles - vm->cycles_to_die) == 0 && check_players2(vm) < 2)
	|| (vm->processes <= 0 || vm->cycles_to_die <= 0))
	{
		ft_printf(SHOW_CURSOR);
		write(fd, "];\n", 3);
		write(fd, "winner = \"", 10);
		if (vm->last_live && !(winner = ft_strdup(vm->last_live->name)))
			error_exit(vm, "malloc failure in fl_matrix_end");
		if (!(vm->last_live) && !(winner = ft_strdup("Nobody")))
			error_exit(vm, "malloc failure in fl_matrix_end");
		write(fd, winner, ft_strlen(winner));
		free(winner);
		write(fd, "\";\n", 3);
		close(fd);
		system("open -a \"Google Chrome\" ./matrix/matrix.html");
		if (*memory2)
			free(*memory2);
		exit(1);
	}
}

void		fl_memcpy(t_vm *vm, int **memory2)
{
	int		j;
	t_champ	*tmp;

	if (*memory2)
		free(*memory2);
	j = 0;
	if (!(*memory2 = (int *)malloc(MEM_SIZE * sizeof(int))))
		error_exit(vm, "malloc failure in fl_memcpy");
	while (j < MEM_SIZE)
	{
		tmp = vm->champs;
		(*memory2)[j] = (unsigned char)vm->memory[j];
		while (tmp)
		{
			(*memory2)[j] = (tmp->pc == j)
			? (*memory2)[j] + 1000 : (*memory2)[j];
			tmp = tmp->next;
		}
		j++;
	}
}
