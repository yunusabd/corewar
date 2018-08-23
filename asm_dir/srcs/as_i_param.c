/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_i_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

int	as_si(char *line, t_list_byte **code)
{
	int		i;
	int		j;
	char	c;
	int		num;

	j = as_j(0, 0);
	i = j;
	while (line[j] == '-' || ft_isdigit(line[j]))
		j++;
	c = line[j];
	line[j] = '\0';
	num = ft_atoi(line + i);
	line[j] = c;
	i = IND_SIZE;
	if (!as_add_bytes(code, i, 9))
		return (0);
	as_write_bytes(code, num, i);
	return (1);
}

int	as_ilabel(char *l, t_list_label **label, int byte_pos, t_list_byte **code)
{
	int		j;
	int		k;
	char	c;

	j = as_j(0, 0) + 1;
	as_skip_space(l, &j);
	k = j;
	as_skip_label2(l, &j);
	c = l[j];
	l[j] = '\0';
	byte_pos = (as_cmp_label(*label, l, k)) - byte_pos;
	if (!as_add_bytes(code, IND_SIZE, 9))
		return (0);
	as_write_bytes(code, byte_pos, IND_SIZE);
	l[j] = c;
	return (1);
}

int	as_ind(char *line)
{
	int j;

	j = as_j(0, 0);
	if (line[j] == LABEL_CHAR)
		return (2);
	else if (ft_isdigit(line[j]) || line[j] == '-')
		return (1);
	return (0);
}
