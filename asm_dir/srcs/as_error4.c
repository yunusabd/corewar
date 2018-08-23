/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/25 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <unistd.h>

char	*as_param_error(int a, int b, t_list_error **error)
{
	char	*msg;
	int		len;
	char	*a_str;
	char	*b_str;

	len = 65 + ft_numlen(a) + ft_numlen(b);
	a_str = NULL;
	b_str = NULL;
	if (!(msg = ft_strnew(len))
	|| !(a_str = ft_itoa(a))
	|| !(b_str = ft_itoa(b)))
	{
		as_malloc_error1(error, 8);
		return (NULL);
	}
	ft_strnfill(msg, '\0', len);
	ft_strcat(msg, ERROR18);
	ft_strcat(msg, a_str);
	ft_strcat(msg, ERROR18B);
	ft_strcat(msg, b_str);
	ft_strcat(msg, "\n");
	free(a_str);
	free(b_str);
	return (msg);
}
