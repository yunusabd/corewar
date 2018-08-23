NAME = libft.a

C_FILES = ft_strcpy.c \
ft_strchr.c \
ft_putchar.c \
ft_putnbr.c \
ft_memset.c \
ft_putstr.c \
ft_strlen.c \
ft_isdigit.c \
ft_atoi.c \
ft_bzero.c \
ft_strncpy.c \
ft_strstr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strcat.c \
ft_strncat.c \
ft_tolower.c \
ft_toupper.c \
ft_isprint.c \
ft_isascii.c \
ft_isalpha.c \
ft_isalnum.c \
ft_strnstr.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_strdup.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlcat.c \
ft_strrchr.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strsplit.c \
ft_itoa.c \
ft_putendl.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_any.c \
ft_isspace.c \
ft_count_if.c \
ft_foreach.c \
ft_map.c \
ft_recursive_factorial.c \
ft_recursive_power.c \
ft_sqrt.c \
ft_strrev.c \
ft_swap.c \
ft_itoa_base.c \
ft_strchlen.c \
ft_strdiv.c \
ft_numlen.c \
ft_stroneleft.c \
ft_strnfill.c \
ft_putwstr.c \
ft_wstrlen.c \
ft_wstrdup.c \
ft_wstrcpy.c \
ft_wstrnew.c \
ft_wstrnfill.c \
ft_wstrjoin.c \
ft_longlongtoa.c \
ft_uitoa_base.c \
ft_putwchar.c \
ft_addtoa.c \
ft_ftoa.c \
ft_round.c \
ft_avany.c \
ft_hasnondigits.c \
ft_atoll.c \
get_next_line.c \
ft_printf.c \
ft_strtablen.c \
ft_freestrtab.c \
ft_str_isalnumsp.c \
ft_str_isalnum.c \
ft_count_char.c

O_FILES = $(C_FILES:%.c=%.o)

PRINTF_SRC = ft_pf_alter ft_pf_handle_chars ft_pf_handle_f_mod \
ft_pf_handle_print ft_pf_handle_strings ft_pf_handle ft_pf_num_mod \
ft_pf_precision ft_pf_sign ft_pf_store_b ft_pf_store ft_pf_struct_init \
ft_pf_width

FT_PF_C_FILES = $(patsubst %,ft_printf/%.c, $(PRINTF_SRC))
FT_PF_O_FILES = $(patsubst %,%.o, $(PRINTF_SRC))

all: $(NAME)

 $(FT_PF_O_FILES): $(FT_PF_C_FILES)
	@gcc $(FLAGS) -c $(FT_PF_C_FILES) -I ../includes
	@echo '\033[0;32m'*** ft_printf objects created ***'\033[0m'

$(NAME): $(O_FILES) $(FT_PF_O_FILES) ../includes/libft.h
	@ar -rc $(NAME) $(FT_PF_O_FILES) $(O_FILES)
	@echo '\033[0;32m'*** libft library compiled ***'\033[0m'

$(O_FILES): $(C_FILES)
	@gcc -Wall -Werror -Wextra -c $(C_FILES) -I ../includes
	@echo '\033[0;32m'*** libft objects created ***'\033[0m'

clean:
	@/bin/rm -rf $(O_FILES) $(FT_PF_O_FILES)
	@echo '\033[0;32m'*** libft objects deleted ***'\033[0m'

fclean: clean
	@/bin/rm -f $(NAME)
	@echo '\033[0;32m'*** libft library deleted ***'\033[0m'

re: fclean all