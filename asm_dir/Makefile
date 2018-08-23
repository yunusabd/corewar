# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 19:09:41 by jszabo            #+#    #+#              #
#    Updated: 2018/08/23 11:47:39 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS = -Werror -Wextra -Wall

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
INCLUDES_DIR = ./includes/

HEADER_FILES = as_errors asm_prot asm_struct colors op libft

HEADERS = $(addsuffix .h, $(patsubst %, $(INCLUDES_DIR)%, $(HEADER_FILES)))

OBJS_DIR = ./objs/
SRCS_DIR = ./srcs/

FILES = as_d_error as_d_param \
as_error_check as_error_check2 as_error_check3 as_error_check4 as_error_check5 \
as_error_print as_error_print2 as_error_print3 as_error_print4 as_error_print5 \
as_error_tracking as_error_tracking2 \
as_error as_error2 as_error3 as_error4 \
as_free as_i_error as_i_param as_init as_init2 \
as_output as_output2 as_output3 \
as_param \
as_parse as_parse2 as_parse3 \
as_r_error \
as_skip as_skip2 \
as_store as_store2 as_store3 \
as_utility as_utility2 \
asm op

OBJS = $(patsubst %, $(OBJS_DIR)%.o, $(FILES))

INCLUDES = -I $(INCLUDES_DIR)

all: libftcomp $(NAME)

$(NAME): $(LIBFT) $(HEADERS) $(OBJS_DIR) $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES)
	@echo '\033[0;32m'*** $(NAME) compiled ***'\033[0m'

libftcomp:
	@make -C $(LIBFT_DIR)

$(OBJS): $(HEADERS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo '\033[0;32m'*** compiling $< to object ***'\033[0m'
	@gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@rm -rf $(OBJS_DIR)
	@echo '\033[0;32m'*** $(NAME) object files cleaned ***'\033[0m'

fclean: clean
	@make -C $(LIBFT_DIR)/ fclean
	@rm -rf $(NAME)
	@echo '\033[0;32m'*** $(NAME) executable cleaned ***'\033[0m'

re: fclean all

.PHONY: all clean fclean re
