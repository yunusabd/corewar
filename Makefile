# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 19:09:41 by jszabo            #+#    #+#              #
#    Updated: 2018/08/22 14:33:29 by jszabo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
COREWAR = corewar
NAME = $(ASM) $(COREWAR)

ASM_DIR = asm_dir
VM_DIR = vm

all: make_asm make_vm $(NAME)

make_asm:
	@make -C $(ASM_DIR)/

make_vm:
	@make -C $(VM_DIR)/

$(NAME): $(ASM_DIR)/$(ASM) $(VM_DIR)/$(COREWAR)
	@cp $(ASM_DIR)/$(ASM) $(ASM)
	@cp $(VM_DIR)/$(COREWAR) $(COREWAR)

clean:
	@make -C $(ASM_DIR)/ clean
	@make -C $(VM_DIR)/ clean

fclean:
	@make -C $(ASM_DIR)/ fclean
	@make -C $(VM_DIR)/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all make_asm make_vm clean fclean re