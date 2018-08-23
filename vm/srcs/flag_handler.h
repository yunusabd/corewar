/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:41:27 by jszabo            #+#    #+#             */
/*   Updated: 2018/08/18 17:41:28 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_HANDLER_H
# define FLAG_HANDLER_H
# include "vm.h"

# define USE "Usage: ./corewar [-dump/-v cycle_nbr] [[-n nbr] x.cor] [-m]"
# define DUMP (1 << 3)
# define VIS (1 << 21)
# define MATRIX (1 << 12)

void	fl_get(int ac, char **av, t_vm *vm);
int		fl_champ(char **av, t_vm *vm, int *i, int ac);
int		fl_n(char **av, t_vm *vm, int *i, int ac);
void	fl_normalize_champ_nr(t_vm *vm);
int		champs_num(t_champ *champ);
void	fl_write_matrix(t_vm *vm);
int		determine_no(t_vm *vm, int no);
int		fl_isspace(int c);
long	fl_atoi_l(const char *str);
int		fl_isnumber(char *s);
void	fl_memcpy(t_vm *vm, int **memory2);
void	fl_matrix_end(t_vm *vm, int fd, int **memory2);
void	fl_get_val(t_champ **tmp, t_vm *vm, int *val, int l);
void	fl_write_first(int val, t_vm *vm, int fd, int l);
void	fl_write_compr(int l, t_vm *vm, int fd, int val);
void	fl_make_champ(t_champ **champ, t_vm *vm);
void	fl_write_data_num(int data, t_vm *vm, int fd);
void	fl_free_champ(t_champ **champ);

#endif
