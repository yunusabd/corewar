# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 13:45:52 by yabdulha          #+#    #+#              #
#    Updated: 2018/08/22 00:00:57 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_FILES = main.c create_vm.c create_champ.c add_champ.c error_handler.c \
			check_magic_number.c reader.c parse_bytes.c order_champs.c \
			get_name.c get_comment.c get_size.c dump_memory.c \
			load_process.c run_champs.c op.c op_sti.c move_pc.c init_params.c \
			check_reg.c op_and.c add_two_octets.c resolve_params.c \
			get_params.c op_live.c op_zjmp.c op_ld.c op_add.c op_fork.c \
			op_st.c op_sub.c op_or.c op_xor.c put_reg.c op_ldi.c op_lld.c \
			op_lldi.c op_lfork.c resolve_indirect.c cycle_check.c find_champ.c \
			judgement_day.c kill_process.c op_aff.c \
			flag_handler.c flag_handler2.c flag_handler3.c flag_handler4.c \
			matrix.c matrix2.c
SRCS_PATH = srcs/
SRCS = $(addprefix $(SRCS_PATH),$(SRC_FILES))

FLAGS = -Werror -Wextra -Wall

OBJS_PATH = objects/
OBJS_NAME = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

INCLUDES_PATH = includes/

INCLUDES_NAME = vm.h op.h flag_handler.h
INCLUDES = $(addprefix $(INCLUDES_PATH),$(INCLUDE_NAME))

LIBFT_PATH = libft
LIB = $(addprefix $(LIBFT_PATH)/,libft.a)

FT_PRINTF = libft/ft_printf/libftprintf.a

PRINTF_PATH = libft/ft_printf/
PRINTF_NAME = libftprintf.a
PRINTF_A = $(addprefix $(PRINTF_PATH),$(PRINTF_NAME))
PRINTF_H = $(addprefix $(PRINTF_PATH),includes/ft_printf.h)

.SILENT: all, clean, fclean, re
.PHONY: all, clean, fclean, re

all: libftcomp $(NAME)

printfcomp:
	@make -C libft/ft_printf/ all

libftcomp:
	@make -C libft/ all

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) libft/libft.a
	@echo '\033[0;32m'***Compiled***'\033[0m'

$(OBJS): $(SRCS) $(INCLUDES_PATH)
	@echo '\033[0;34m'***Compiling Virtual Machine***'\033[0m'
	@gcc $(FLAGS) -I$(INCLUDES_PATH) -c $(SRCS)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mv $(OBJS_NAME) $(OBJS_PATH)

clean:
	@/bin/rm -rf $(OBJS_PATH)
	@make -C libft/ clean 2> /dev/null || true
	@echo '\033[0;31m'***Deleted objects***'\033[0m'

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean 2> /dev/null || true
	@echo '\033[0;31m'***Deleted objects and library***'\033[0m'

re: fclean all
