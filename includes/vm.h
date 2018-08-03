/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:30 by yabdulha          #+#    #+#             */
/*   Updated: 2018/08/03 01:32:16 by yabdulha         ###   ########.fr       */
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

typedef struct		s_byte
{
	char				byte;
	struct s_byte		*next;
}					t_byte;

typedef struct		s_champ
{
	int				carry;
	short int		magic;
	int				number;
	int				size;
	int				op;
	int				reg[REG_NUMBER];
	int				pc;
	int				pc_tmp;
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
	int			players;
	char		**av;
	t_champ		*champs;
	int			memory[MEM_SIZE];

}					t_vm;

typedef	struct		s_exec
{
	int			opcode;
	int			dest;
	int			src;
	int			res;
}					t_exec;

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
void				load_processes(t_vm *vm);
void				run_champs(t_vm *vm);
void				move_pc(int *pc, int n);

t_exec				*init_exec(t_vm *vm);
void				op_sti(t_vm *vm, t_champ *champ, t_exec *exec);
#endif
