/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:04:49 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/18 18:04:49 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

static void	update_prev(t_vm *vm, int no, int i)
{
	t_champ *tmp;

	if (no != 0)
	{
		tmp = vm->champs;
		while (tmp)
		{
			if (tmp->number == -no)
				tmp->number = i;
			tmp = tmp->next;
		}
	}
}

int			determine_no(t_vm *vm, int no)
{
	int		i;
	t_champ	*tmp;
	int		changed;

	i = 1;
	changed = 0;
	tmp = vm->champs;
	while (tmp)
	{
		changed = 0;
		if (tmp->number == i || tmp->number == -i)
		{
			changed = 1;
			i++;
			if (i > MAX_PLAYERS)
				i = 1;
		}
		tmp = (changed) ? vm->champs : tmp->next;
	}
	update_prev(vm, no, i);
	return (no == 0) ? (i) : (no);
}

int			fl_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
	c == '\f' || c == '\r') ? (1) : (0);
}

long		fl_atoi_l(const char *str)
{
	int			i;
	int			negative;
	intmax_t	result;

	i = 0;
	result = 0;
	negative = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		negative = (str[i++] == '-') ? 1 : 0;
	while (str[i] == '0')
		i++;
	if (!(ft_isdigit(str[i])))
		return (0);
	while (ft_isdigit(str[i]) == 1)
		result = (result * 10 - (str[i++] - '0'));
	if (!negative)
		result = -result;
	if (result > LONG_MAX)
		return (0);
	if (result < LONG_MIN)
		return (0);
	return ((long)result);
}

int			fl_isnumber(char *s)
{
	int	i;

	i = 0;
	if (!s || !(*s))
		return (0);
	while (*s && *s == 32)
		s++;
	if (*s == '-' || *s == '+')
		s++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			i++;
		else if (s[i] == ' ')
		{
			s++;
			if (ft_isdigit(s[i]))
				return (0);
		}
		else
			return (0);
	}
	return ((i) ? 1 : 0);
}
