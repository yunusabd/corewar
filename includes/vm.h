/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:30 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/06 23:55:55 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "../libft/libft.h"

# include <fcntl.h>
# include <stdio.h>
//remove
# include <stdlib.h>
# include <unistd.h>

# define READ_BUFF_SIZE	40

# define CLEAR			"\x1b[H\x1b[2J"
# define CUR_RESET		"\x1b[H\x1b[?25l"
# define SHOW_CURSOR	"\x1b[?12;25h"

#define BLK		"\x1B[30m"
#define RED		"\x1B[31m"
#define GRN		"\x1B[32m"
#define YEL		"\x1B[33m"
#define BLU		"\x1B[34m"
#define MAG		"\x1B[35m"
#define CYN		"\x1B[36m"
#define WHT		"\x1B[37m"
#define RESET	"\x1B[0m"

#define BRESET	"\x1B[40m"
#define BRED	"\x1B[41m"
#define BGRN	"\x1B[42m"
#define BYEL	"\x1B[43m"
#define BBLU	"\x1B[44m"
#define BMAG	"\x1B[45m"
#define BCYN	"\x1B[46m"
#define BWHT	"\x1B[47m"


typedef struct		s_byte
{
	char				byte;
	struct s_byte		*next;
}					t_byte;

typedef	struct		s_params
{
	int			opcode;
	int			encoding_byte;
	int			p1;
	int			p2;
	int			p3;
}					t_params;

typedef struct		s_champ
{
	short int		magic;
	int				carry;
	int				cycles;
	int				encoding_byte;
	int				number;
	int				opcode;
	int				pc;
	int				pc_tmp;
	int				size;
	int				start;
	intmax_t		reg[REG_NUMBER];
	t_params		*params;
	char			*name;
	char			*data;
	char			*comment;
	char			*filename;
	t_byte			*bytes;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_vm
{
	int			ac;
	int			cycles;
	int			players;
	char		**av;
	t_champ		*champs;
	int			memory[MEM_SIZE];

}					t_vm;

typedef struct				s_op
{
	char					*opname;
	int						param_count;
	int						param_type[3];
	int						opcode;
	int						cycles;
	char					*description;
	int						acb;
	int						half_size;
}							t_op;

extern t_op			g_op_tab[17];

t_vm				*create_vm(int ac, char **av);
t_champ				*create_champ(t_vm *vm);
void				add_champ(t_vm *vm, t_champ *champ);
void				error_exit(t_vm *vm, char *msg);
void				free_champ(t_champ *champ);
void				check_magic_number(t_vm *vm, t_champ *champ, char *buff);

int					reader(t_vm *vm, int no, char *path);
int					parse_bytes(t_vm *vm, t_champ *champ);
void				get_name(t_vm *vm, t_champ *champ);
void				get_size(t_vm *vm, t_champ *champ);
void				get_comment(t_vm *vm, t_champ *champ);

void				dump_memory(t_vm *vm);
void				dump_handler(t_vm *vm);
void				load_processes(t_vm *vm);
void				run_champs(t_vm *vm);
void				move_pc(int *pc, int n);

void				get_params(t_vm *vm, t_champ *champ);
int					check_reg(int reg);
int					add_two_octets(t_vm *vm, int pc);
t_params			*init_params(t_vm *vm);
void				resolve_params(t_vm *vm, t_champ *champ, t_params *param,
		int n);
void				get_direct(t_vm *vm, t_champ *champ, int *j);
void				op_sti(t_vm *vm, t_champ *champ);
void				op_and(t_vm *vm, t_champ *champ);
void				op_live(t_vm *vm, t_champ *champ);
void				op_zjmp(t_vm *vm, t_champ *champ);
void				op_ld(t_vm *vm, t_champ *champ);
#endif
