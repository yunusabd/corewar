/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_d_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/16 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

int	as_sd(char *line, t_list_byte **code)
{
	int		i;
	int		j;
	char	c;
	int		num;
	int		pos;

	j = as_j(0, 0) + 1;
	pos = as_get_pos(0, 0);
	as_skip_space(line, &j);
	i = j;
	while (line[j] == '-' || ft_isdigit(line[j]))
		j++;
	c = line[j];
	line[j] = '\0';
	num = ft_atoi(line + i);
	line[j] = c;
	i = (pos == 8 || pos == 9 || pos == 10 || pos == 11
	|| pos == 13 || pos == 14)
	? IND_SIZE : DIR_SIZE;
	if (!as_add_bytes(code, i, 3))
		return (0);
	as_write_bytes(code, num, i);
	return (1);
}

int	as_dlabel(char *l, t_list_label **label, int byte_pos, t_list_byte **code)
{
	int			j;
	int			k;
	char		c;
	int			i;
	int			pos;

	j = as_j(0, 0) + 2;
	pos = as_get_pos(0, 0);
	as_skip_space(l, &j);
	k = j;
	as_skip_label2(l, &j);
	c = l[j];
	l[j] = '\0';
	byte_pos = (as_cmp_label(*label, l, k)) - byte_pos;
	i = (pos == 8 || pos == 9 || pos == 10 || pos == 11
	|| pos == 13 || pos == 14)
	? IND_SIZE : DIR_SIZE;
	if (!as_add_bytes(code, i, 3))
		return (0);
	as_write_bytes(code, byte_pos, i);
	l[j] = c;
	return (1);
}

int	as_d(char *line)
{
	int j;
	int ret;

	ret = 0;
	j = as_j(0, 0);
	if (line[j] == DIRECT_CHAR)
		ret++;
	if (ret && line[j + 1] && line[j + 1] == LABEL_CHAR)
		ret++;
	return (ret);
}
