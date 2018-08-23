/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:20:40 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/28 15:01:07 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCT_H
# define ASM_STRUCT_H

typedef struct				s_list_byte
{
	unsigned char			byte;
	int						type;
	struct s_list_byte		*next;
}							t_list_byte;

typedef struct				s_list_label
{
	char					*name;
	int						pos;
	struct s_list_label		*next;
}							t_list_label;

typedef struct				s_list_error
{
	int						type;
	char					*line;
	char					*message;
	int						line_nr;
	int						column_nr;
	struct s_list_error		*next;
}							t_list_error;

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

typedef struct				s_flags
{
	int						w;
	int						v;
	int						p;
	int						a;
}							t_flags;

extern t_op					g_op_tab[17];

#endif
