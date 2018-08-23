/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:30:08 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/22 18:58:20 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "flag_handler.h"

static int	fl_v(char **av, t_vm *vm, int *i, int ac)
{
	static int	v_ct = 0;

	if (!ft_strcmp(av[*i], "-v"))
	{
		if (vm->flags & DUMP || v_ct > 0)
			error_exit(vm, USE);
		v_ct++;
		vm->flags += 2097152;
		(*i)++;
		if (*i == ac || !fl_isnumber(av[*i]) || fl_isspace(av[*i][0]) ||
		av[*i][0] == '-' || av[*i][0] == '+')
			error_exit(vm, USE);
		if (ft_strlen(av[*i]) > 5)
			error_exit(vm, "cycle number has to be under 100000");
		vm->offset = ft_atoi(av[*i]);
		if (vm->offset < 1)
			error_exit(vm, USE);
		(*i)++;
	}
	if (*i == ac)
		return (0);
	return (1);
}

static int	fl_m(char **av, t_vm *vm, int *i, int ac)
{
	static int	m_ct = 0;

	if (!ft_strcmp(av[*i], "-m"))
	{
		if (m_ct > 0)
			error_exit(vm, USE);
		m_ct++;
		vm->flags += 4096;
		(*i)++;
	}
	if (*i == ac)
		return (0);
	return (1);
}

static int	fl_dump(char **av, t_vm *vm, int *i, int ac)
{
	static int	dump_ct = 0;

	if (!ft_strcmp(av[*i], "-dump"))
	{
		if (vm->flags & VIS || dump_ct > 0)
			error_exit(vm, USE);
		dump_ct++;
		vm->flags += 8;
		(*i)++;
		if (*i == ac || !fl_isnumber(av[*i]) || fl_isspace(av[*i][0]) ||
		av[*i][0] == '-' || av[*i][0] == '+')
			error_exit(vm, USE);
		if (ft_strlen(av[*i]) > 5)
			error_exit(vm, "cycle number has to be under 100000");
		vm->offset = ft_atoi(av[*i]);
		if (vm->offset < 1)
			error_exit(vm, USE);
		(*i)++;
	}
	if (*i == ac)
		return (0);
	return (1);
}

static int	fl_valid_input(char **av, t_vm *vm, int *i)
{
	if (ft_strcmp(av[*i], "-dump") &&
		ft_strcmp(av[*i], "-n") &&
		ft_strcmp(av[*i], "-v") &&
		ft_strcmp(av[*i], "-m") &&
		ft_strcmp(av[*i] + ft_strlen(av[*i]) - 4, ".cor"))
		error_exit(vm, USE);
	return (1);
}

void		fl_get(int ac, char **av, t_vm *vm)
{
	int	i;

	i = 1;
	if (ac == 1)
		error_exit(vm, USE);
	while (i < ac)
	{
		if (!fl_valid_input(av, vm, &i) ||
			!fl_dump(av, vm, &i, ac) ||
			!fl_n(av, vm, &i, ac) ||
			!fl_v(av, vm, &i, ac) ||
			!fl_m(av, vm, &i, ac) ||
			!fl_champ(av, vm, &i, ac))
			break ;
	}
	fl_normalize_champ_nr(vm);
	order_champs(vm);
}
