# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 13:45:52 by yabdulha          #+#    #+#              #
#    Updated: 2018/08/23 11:48:35 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FILES = main.c create_vm.c create_champ.c add_champ.c error_handler.c \
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

FLAGS = -Werror -Wextra -Wall

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
INCLUDES_DIR = ./includes/

HEADER_FILES = flag_handler op vm

HEADERS = $(addsuffix .h, $(patsubst %, $(INCLUDES_DIR)%, $(HEADER_FILES)))

OBJS_DIR = ./objs/
SRCS_DIR = ./srcs/

OBJS = $(patsubst %.c, $(OBJS_DIR)%.o, $(FILES))

INCLUDES = -I $(INCLUDES_DIR)

all: libftcomp $(NAME)

$(NAME): $(HEADERS) $(OBJS_DIR) $(OBJS) $(LIBFT)
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
	@/bin/rm -rf $(OBJS_DIR)
	@make -C libft/ clean 2> /dev/null || true
	@echo '\033[0;31m'***Deleted objects***'\033[0m'

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean 2> /dev/null || true
	@echo '\033[0;31m'***Deleted objects and library***'\033[0m'

re: fclean all

.SILENT: all, clean, fclean, re
.PHONY: all, clean, fclean, re
