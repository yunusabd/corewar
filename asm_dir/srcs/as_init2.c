/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/03 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "as_errors.h"
#include "colors.h"
#include <fcntl.h>

void	as_ccheck_init(int *bc, int *i, int *j, char *line)
{
	*bc = (*bc) + COMMENT_LENGTH + 8;
	*i = 0;
	as_skip_space(line, i);
	*i = *i + ft_strlen(COMMENT_CMD_STRING);
	*j = *i;
	as_skip_space(line, i);
}

void	as_ncheck_init(int *bc, int *i, int *j, char *line)
{
	*bc = (*bc) + PROG_NAME_LENGTH + 4;
	*i = 0;
	as_skip_space(line, i);
	*i = *i + ft_strlen(NAME_CMD_STRING);
	*j = *i;
	as_skip_space(line, i);
}
