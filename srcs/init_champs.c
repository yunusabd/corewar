/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:16:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/02 14:21:15 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_opcode(t_champ *champ)
{
	printf("opcode: %d\n", champ->data[champ->pc]);
}

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
	while (i > 0)
	{
		print_encoding(((c >> i) & 3), i);
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
		get_opcode(tmp);
		get_encoding(tmp->data[1]);
		tmp = tmp->next;
	}
}
