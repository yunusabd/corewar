/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:04:49 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/23 08:33:30 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static void	fl_write_opcode(int fd, t_vm *vm)
{
	t_champ *champ;
	t_champ *tmp;

	fl_make_champ(&champ, vm);
	write(fd, " [[", 3);
	tmp = champ;
	while (champ)
	{
		fl_write_data_num(champ->carry, vm, fd);
		write(fd, ", ", 2);
		fl_write_data_num(champ->opcode, vm, fd);
		write(fd, ", ", 2);
		fl_write_data_num(champ->number, vm, fd);
		if (champ->next)
			write(fd, ", ", 2);
		champ = champ->next;
	}
	champ = tmp;
	fl_free_champ(&champ);
	write(fd, "], [", 4);
}

static void	fl_write_memory(int fd, t_vm *vm, int *memory2, int i)
{
	int			l;
	int			val;
	t_champ		*tmp;
	int			change;

	change = 0;
	l = 0;
	while (l < MEM_SIZE)
	{
		fl_get_val(&tmp, vm, &val, l);
		if (!i)
			fl_write_first(val, vm, fd, l);
		else if (memory2[l] != val)
		{
			if (change)
				write(fd, ", ", 2);
			fl_write_compr(l, vm, fd, val);
			change = 1;
		}
		l++;
	}
	write(fd, "], [", 4);
	fl_write_data_num(vm->cycles_to_die, vm, fd);
	write(fd, "]]", 2);
}

static void	fl_write_champ(int fd, t_vm *vm)
{
	t_champ *tmp;

	tmp = vm->champs;
	write(fd, "var champs = [", 14);
	while (tmp)
	{
		write(fd, "[\"", 2);
		write(fd, tmp->name, ft_strlen(tmp->name));
		write(fd, "\", ", 3);
		fl_write_data_num(tmp->number, vm, fd);
		write(fd, "]", 1);
		if (tmp->next)
			write(fd, ", ", 1);
		tmp = tmp->next;
	}
	write(fd, "];\n", 3);
	write(fd, "var memory = [", 14);
}

void		fl_write_matrix(t_vm *vm)
{
	static int	fd = 0;
	static int	i = 0;
	static int	*memory2;

	if (!(vm->flags & MATRIX))
		return ;
	if (!i)
	{
		ft_printf(CLEAR);
		fd = open("./vm/matrix/memory.js", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR |
		S_IWUSR | S_IRGRP | S_IROTH);
		fl_write_champ(fd, vm);
	}
	fl_write_opcode(fd, vm);
	fl_write_memory(fd, vm, memory2, i);
	if (vm->processes > 0 && vm->cycles_to_die > 0)
	{
		ft_printf(HIDE_CURSOR);
		if (!(i % 10))
			ft_printf(GRN "  Uploading to the Matrix... %d cycles" RESET, i);
		write(fd, ",", 1);
	}
	fl_matrix_end(vm, fd, &memory2);
	fl_memcpy(vm, &memory2);
	i++;
}

int			champs_num(t_champ *champ)
{
	t_champ	*tmp;
	int		i;

	tmp = champ;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
