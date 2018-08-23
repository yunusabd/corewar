/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:33:32 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/22 16:28:53 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2,
					size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src,
					int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strdup(const char *s1);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_any(char **tab, int (*f)(char*));
int					ft_count_if(char **tab, int (*f)(char*));
void				ft_foreach(int *tab, int length, void (*f)(int));
int					*ft_map(int *tab, int length, int (*f)(int));
int					ft_recursive_factorial(int nb);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
char				*ft_strrev(char *str);
void				ft_swap(int *a, int *b);
char				*ft_itoa_base(int value, int base);
int					ft_printf(char *format, ...);
int					ft_strchlen(char *str, char c);
char				*ft_strdiv(char **src, char *new, int n);
int					ft_stroneleft(char **str);
int					ft_numlen(int a);
char				*ft_strnfill(char *str, char c, int n);
int					ft_putwstr(const wchar_t *s);
int					ft_wstrlen(const wchar_t *s);
wchar_t				*ft_wstrdup(wchar_t *s1);
wchar_t				*ft_wstrcpy(wchar_t *dst, const wchar_t *src);
wchar_t				*ft_wstrnew(int size);
wchar_t				*ft_wstrnfill(wchar_t *str, wchar_t c, int n);
wchar_t				*ft_wstrjoin(const wchar_t *s1, const wchar_t *s2);
char				*ft_longlongtoa(long long n);
char				*ft_uitoa_base(unsigned long long value, int base);
int					ft_putwchar(wchar_t c);
int					ft_addtoa(char **num);
char				*ft_ftoa(double n, size_t pr);
double				ft_round(double n);
int					ft_avany(char **argv, int argc, int (*f)(char*));
int					ft_hasnondigits(char *str);
long long			ft_atoll(const char *str);
int					get_next_line(const int fd, char **line);
int					ft_printf(char *format, ...);
int					ft_strtablen(char **tab);
void				ft_freestrtab(char ***tab);
int					ft_str_isalnumsp(char *str);
int					ft_str_isalnum(char *str);
int					ft_count_char(char *str, char c);

#endif
