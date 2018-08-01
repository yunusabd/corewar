/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:16:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/02 00:24:49 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_encoding(int n, int i)
{
	char	*pos;
	char	*type[3] = {"register", "direct", "indirect"};

	if (i == 6)
		pos = "First param";
	else if (i == 4)
		pos = "Second param";
	else if (i == 2)
		pos = "Third param";
	printf("%s: %s\n", pos, type[n - 1]);
}

void	get_encoding(char c)
{
	int	i;

	i = (sizeof(c) * 8) - 2;
	while (i >= 0)
	{
		if (((c >> i) & 3) == 3)
			print_encoding(3, i);
		else if (((c >> i) & 1) == 1)
			print_encoding(1, i);
		else if (((c >> i) & 2) == 2)
			print_encoding(2, i);
		printf("\n");
		i -= 2;
	}
	printf("[%.2x]", c);
}

void	run_champs(t_vm *vm)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		get_encoding(tmp->data[1]);
		tmp = tmp->next;
	}
}
