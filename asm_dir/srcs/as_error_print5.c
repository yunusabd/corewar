/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_error_print5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/24 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm_struct.h"
#include "asm_prot.h"
#include "colors.h"
#include "as_errors.h"
#include <fcntl.h>

int		as_writing_error(t_list_byte **code, char *nn)
{
	as_free(code);
	return (as_err2(ERROR36, nn));
}

void	as_errnbr(int n)
{
	char c;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			as_errnbr(-214748364);
			c = '8';
			write(2, &c, 1);
			return ;
		}
		c = '-';
		write(2, &c, 1);
		n *= -1;
	}
	if (n > 9)
		as_errnbr(n / 10);
	c = n % 10 + 48;
	write(2, &c, 1);
}

void	as_label_error(char *message, int lnr, char *line, int cnr)
{
	as_err1(ERROR28, lnr, line, cnr);
	if (message)
		as_note_label(lnr, cnr, message);
}

int		as_malloc_error2(t_list_byte **code, int a)
{
	ft_putstr_fd(BOLDYELLOW "system error:" RESET, 2);
	ft_putstr_fd(BOLDWHITE " malloc failure" RESET, 2);
	if (a == 1)
		ft_putstr_fd(WHITE " (as_wfile)\n" RESET, 2);
	else if (a == 2)
		ft_putstr_fd(WHITE " (as_flags_init)\n" RESET, 2);
	else if (a == 3)
		ft_putstr_fd(WHITE " (as_add_label)\n" RESET, 2);
	else if (a == 4)
		ft_putstr_fd(WHITE " (as_add_byte)\n" RESET, 2);
	as_free(code);
	return (0);
}
