# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 13:45:52 by yabdulha          #+#    #+#              #
#    Updated: 2018/07/26 14:11:11 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_FILES = main.c add_bytes.c create_vm.c create_champ.c error_handler.c 
SRCS_PATH = srcs/
SRCS = $(addprefix $(SRCS_PATH),$(SRC_FILES))

# FLAGS = -Werror -Wextra -Wall

OBJS_PATH = objects/
OBJS_NAME = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

INCLUDES_PATH = includes/

INCLUDES_NAME = vm.h op.h
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
