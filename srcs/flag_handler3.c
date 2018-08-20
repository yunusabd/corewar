/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:04:49 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/20 17:12:23 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static void	fl_write_opcode(int fd, t_vm *vm)
{
	char	*num;
	t_champ *tmp;

	tmp = vm->champs;
	write(fd, " [[", 3);
	while (tmp)
	{
		if (!(num = ft_itoa(tmp->opcode)))
			error_exit(vm, "malloc failure in fl_write_opcode");
		free(num);
		write(fd, num, ft_strlen(num));
		if (tmp->next)
			write(fd, ", ", 2);
		tmp = tmp->next;
	}
	write(fd, "], [", 4);
}

static void	fl_write_memory(int fd, t_vm *vm)
{
	int			i;
	int			val;
	char		*num;
	t_champ		*tmp;
	static int	zero_ct = 0;

	i = 0;
	fl_write_opcode(fd, vm);
	while (i < MEM_SIZE)
	{
		tmp = vm->champs;
		val = (unsigned char)(vm->memory)[i];
		while (tmp)
		{
			val = (tmp->pc == i) ? val + 1000 : val;
			tmp = tmp->next;
		}
		if (!val)
		{
			zero_ct++;
			if (i == MEM_SIZE - 1)
			{
				if (!(num = ft_itoa(-zero_ct)))
					error_exit(vm, "malloc failure in fl_write_memory");
				write(fd, num, ft_strlen(num));
				free(num);
			}
		}
		else
		{
			if (zero_ct)
			{
				if (!(num = ft_itoa(-zero_ct)))
					error_exit(vm, "malloc failure in fl_write_memory");
				write(fd, num, ft_strlen(num));
				free(num);
				write(fd, ", ", 2);
			}
			if (!(num = ft_itoa(val)))
					error_exit(vm, "malloc failure in fl_write_memory");
			write(fd, num, ft_strlen(num));
			free(num);
			zero_ct = 0;
		}
		// if (!(num = ft_itoa(val)))
		// 	error_exit(vm, "malloc failure in fl_write_memory");
		// write(fd, num, ft_strlen(num));
		// free(num);
		if (i < MEM_SIZE - 1 && val)
			write(fd, ", ", 2);
		i++;
	}
	write(fd, "]]", 2);
}

static void	fl_write_champ(int fd, t_vm *vm)
{
	char	*num;
	t_champ *tmp;

	tmp = vm->champs;
	write(fd, "var champs = [", 14);
	while (tmp)
	{
		write(fd, "[\"", 2);
		write(fd, tmp->name, ft_strlen(tmp->name));
		write(fd, "\", ", 3);
		if (!(num = ft_itoa(tmp->number)))
			error_exit(vm, "malloc failure in fl_write_champ");
		write(fd, num, ft_strlen(num));
		free(num);
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

	if (!(vm->flags & MATRIX))
		return ;
	if (!i)
	{
		ft_putstr("The Matrix is loading...");
		fd = open("./matrix/memory.js", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR |
		S_IWUSR | S_IRGRP | S_IROTH);
		fl_write_champ(fd, vm);
	}
	fl_write_memory(fd, vm);
	if (vm->processes > 0 && vm->cycles_to_die > 0)
		write(fd, ",", 1);
	if (vm->processes <= 0 || vm->cycles_to_die <= 0)
	{
		write(fd, "];\n", 3);
		close(fd);
		system("open -a \"Google Chrome\" ./matrix/matrix.html");
	}
	i++;
	ft_putchar('.');
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
