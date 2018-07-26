/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:20:30 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 12:34:42 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "../libft/libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define READ_BUFF_SIZE	64

typedef struct		s_byte
{
	char				byte;
	struct s_byte		*next;
}					t_byte;

typedef struct		s_champ
{
	char		*file_name;
	char		*name;
	int			number;
	int			size;
	t_byte		*byte;
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

#endif
