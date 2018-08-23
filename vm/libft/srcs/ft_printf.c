/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 20:44:26 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 13:43:25 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		print_string(char *s)
{
	int count;

	count = 0;
	count += ft_putstr(s);
	free(s);
	return (count);
}

static int		print_arg(va_list ap, t_printf *specs, char *s, int count)
{
	if (specs->converter == '%')
		s = handle_percent(specs);
	else if (specs->converter == 'p')
		s = convert_p(ap, specs);
	else if (specs->converter == 'x' || specs->converter == 'X')
		s = convert_x(ap, specs);
	else if (specs->converter == 'o' || specs->converter == 'O')
		s = convert_o(ap, specs);
	else if (specs->converter == 'd' || specs->converter == 'i')
		s = convert_d(ap, specs);
	else if (specs->converter == 'D')
		s = init_d(ap, specs);
	else if (specs->converter == 'u' || specs->converter == 'U')
		s = convert_u(ap, specs);
	else if (specs->converter == 'c' || specs->converter == 'C')
	{
		s = convert_c(ap, specs);
		if (s == NULL)
			return (empty_string(specs, count));
	}
	else if (specs->converter == 's' || specs->converter == 'S')
		s = init_s(ap, specs);
	else if (specs->converter)
		s = init_s(ap, specs);
	return (print_string(s));
}

static int		parse_format(va_list ap, char **format)
{
	t_printf	new;

	ft_memset(&new, 0, sizeof(t_printf));
	new.converter = 0;
	*format = parse_spec(*format, &new);
	return (print_arg(ap, &new, NULL, 0));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			ret;
	char		*tmp;

	va_start(ap, format);
	ret = 0;
	i = 0;
	tmp = ft_strnew(BUFFSIZE);
	while (*format)
	{
		while (i < BUFFSIZE && *format && *format != '%' && ++ret)
			tmp[i++] = *(format++);
		if (i)
			write(1, tmp, i);
		ft_bzero((void*)tmp, i);
		i = 0;
		if (*format == '%')
			ret += (parse_format(ap, (char**)&format));
	}
	if (i)
		write(1, tmp, i);
	free(tmp);
	va_end(ap);
	return (ret);
}

size_t			ft_wchar_len(wchar_t wc)
{
	if ((int)wc >= 0 && (int)wc <= 0x7F)
		return (1);
	else if ((int)wc <= 0x7FF)
		return (2);
	else if ((int)wc <= 0xFFFF)
		return (3);
	else if ((int)wc <= 0x10FFFF)
		return (4);
	return (0);
}
