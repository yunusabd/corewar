/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:30 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 21:11:27 by yabdulha         ###   ########.fr       */
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
	char			*file_name;
	short int		magic;
	char			*name;
	int				number;
	int				size;
	t_byte			*byte;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_vm
{
	int			ac;
	char		**av;
	t_champ		*champs;
	int			memsize;

}					t_vm;

void		read_bytes(t_champ champ, char *buff, t_byte *head);
t_vm		*create_vm(int ac, char **av);
t_champ		*create_champ(t_vm *vm);
void		add_champ(t_vm *vm, t_champ *champ);
void		error_exit(t_vm *vm, char *msg);
void		free_champ(t_champ *champ);
void		check_magic_number(t_vm *vm, t_champ *champ, char *buff);

#endif
