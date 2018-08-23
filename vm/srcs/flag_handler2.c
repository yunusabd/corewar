/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:30:08 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/22 17:26:24 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static void	fl_sort_champ_nr(t_champ *tmp, t_vm *vm)
{
	int		tmp_num;
	int		changed;
	t_champ *next;

	next = vm->champs;
	while (tmp && next)
	{
		next = tmp;
		changed = 0;
		if (tmp->number > 0)
		{
			next = next->next;
			while (next && next->number <= 0)
				next = next->next;
			if (next && tmp->number < next->number)
			{
				tmp_num = tmp->number;
				tmp->number = next->number;
				next->number = tmp_num;
				changed = 1;
			}
		}
		tmp = (changed) ? vm->champs : tmp->next;
	}
}

void		fl_normalize_champ_nr(t_vm *vm)
{
	t_champ *tmp;

	tmp = vm->champs;
	if (!tmp)
		error_exit(vm, USE);
	fl_sort_champ_nr(tmp, vm);
	while (tmp)
	{
		if (tmp->number < 0)
			tmp->number = -(tmp->number);
		tmp = tmp->next;
	}
}

static void	fl_check_double_n(t_vm *vm, int nr)
{
	t_champ *tmp;

	tmp = vm->champs;
	while (tmp)
	{
		if (tmp->number == -nr)
			error_exit(vm, "Same player number can't be assigned twice");
		tmp = tmp->next;
	}
}

int			fl_n(char **av, t_vm *vm, int *i, int ac)
{
	int nr;

	if (!ft_strcmp(av[*i], "-n"))
	{
		(*i)++;
		if (*i == ac || !fl_isnumber(av[*i]) || fl_isspace(av[*i][0]) ||
		av[*i][0] == '-' || av[*i][0] == '+')
			error_exit(vm, USE);
		if (ft_strlen(av[*i]) > 10 || fl_atoi_l(av[*i]) > 2147483647)
			error_exit(vm, "Player number too large");
		nr = ft_atoi(av[*i]);
		if (nr < 1)
			error_exit(vm, "Player number too small");
		if (nr > MAX_PLAYERS)
			error_exit(vm, "Player number too large");
		fl_check_double_n(vm, nr);
		(*i)++;
		if (*i == ac || ft_strcmp(av[*i] + ft_strlen(av[*i]) - 4, ".cor"))
			error_exit(vm, USE);
		if (vm->champs && champs_num(vm->champs) >= MAX_PLAYERS)
			error_exit(vm, "Too many champions");
		reader(vm, -nr, av[*i]);
		(*i)++;
	}
	return (*i == ac) ? (0) : (1);
}

int			fl_champ(char **av, t_vm *vm, int *i, int ac)
{
	if (!ft_strcmp(av[*i] + ft_strlen(av[*i]) - 4, ".cor"))
	{
		if (vm->champs && champs_num(vm->champs) >= MAX_PLAYERS)
			error_exit(vm, "Too many champions");
		reader(vm, 0, av[*i]);
		(*i)++;
	}
	if (*i == ac)
		return (0);
	return (1);
}
