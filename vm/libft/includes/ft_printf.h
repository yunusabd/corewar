/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:03:52 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/21 13:43:04 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <wchar.h>

# define BUFFSIZE 20
# define SPECIFIERS "sSpdDioOuUxXcCb%"
# define VALID_CHARS "sSpdDioOuUxXcCb%lhjz-+0123456789. #"
# define SP_LEN (ft_strlen(SPECIFIERS))

typedef struct	s_printf
{
	int		iszero;
	int		isspace;
	int		ishash;
	int		isminus;
	int		isplus;

	int		width;
	int		precision;

	int		ishh;
	int		ish;
	int		isll;
	int		isl;
	int		isj;
	int		isz;
	char	converter;
	int		negative;

}				t_printf;

typedef struct	s_ret
{
	char	*value;
	int		len;
}				t_ret;

char			*parse_spec(char *str, t_printf *specs);
int				ft_printf(const char *format, ...);
char			*convert_s(char *str, t_printf *specs);
char			*convert_d(va_list ap, t_printf *specs);
char			*convert_u(va_list ap, t_printf *specs);
char			*convert_x(va_list ap, t_printf *specs);
char			*convert_o(va_list ap, t_printf *specs);
char			*convert_c(va_list ap, t_printf *specs);
char			*convert_p(va_list ap, t_printf *specs);
char			*padding(char *str, t_printf *specs);
char			*handle_unicode(wchar_t c);
char			*wstring(wchar_t *s);
char			*init_d(va_list ap, t_printf *specs);
char			*init_s(va_list ap, t_printf *specs);
char			*handle_percent(t_printf *specs);
int				empty_string(t_printf *specs, int count);
char			*get_len(char *fstr, t_printf *specs);
char			*get_flags(char *fstr, t_printf *specs);

#endif
