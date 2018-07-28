/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:30 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/29 00:00:07 by yabdulha         ###   ########.fr       */
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
	short int		magic;
	int				number;
	int				size;
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
	char		**av;
	t_champ		*champs;
	int			memsize;

}					t_vm;

//void		read_bytes(t_vm *vm, t_champ champ, char *buff, t_byte *head);
t_vm		*create_vm(int ac, char **av);
t_champ		*create_champ(t_vm *vm);
void		add_champ(t_vm *vm, t_champ *champ);
void		error_exit(t_vm *vm, char *msg);
void		free_champ(t_champ *champ);
void		check_magic_number(t_vm *vm, t_champ *champ, char *buff);

int			reader(t_vm *vm, int no, char *path);
int			parse_bytes(t_vm *vm, t_champ *champ);
void		get_name(t_vm *vm, t_champ *champ);
void		get_size(t_vm *vm, t_champ *champ);
void		get_comment(t_vm *vm, t_champ *champ);
#endif
