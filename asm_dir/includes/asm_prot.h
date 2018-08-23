/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_prot.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 15:20:40 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/28 15:01:07 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PROT_H
# define ASM_PROT_H

/*
**      Functions to store information
**      as_store.c
**      as_store2.c
**      as_store3.c
*/

int		as_get_par(char *li, t_list_label **la, t_list_byte **c, t_flags *f);
int		as_get_command(char *line, int i, t_list_byte **code, t_flags *f);
int		as_store_zero(int i, int section, t_list_byte **code);
int		as_store_non_zero(int length, char *line, int *i, t_list_byte **code);
int		as_store(int fd, t_list_label **label, char *filename, t_flags *flags);
int		as_store_magic(t_list_byte **code);
int		as_ssize(t_list_byte **size, t_list_byte *code);

/*
**      Functions to store direct parameters
**      as_d_param.c
*/

int		as_sd(char *line, t_list_byte **code);
int		as_dlabel(char *line, t_list_label **lab, int bp, t_list_byte **c);
int		as_d(char *line);

/*
**      Functions to store indirect parameters
**      as_i_param.c
*/

int		as_si(char *line, t_list_byte **code);
int		as_ilabel(char *line, t_list_label **lab, int bp, t_list_byte **code);
int		as_ind(char *line);

/*
**      Functions to store other parameter data
**      as_param.c
*/

int		as_bw_params(int *i, char *line, t_list_error **error);
int		as_cmp_label(t_list_label *label, char *line, int k);
int		as_enc(t_list_byte **encoding, int start);
int		as_slabel(char *line, int *i, t_list_error **err, t_list_label **lab);

/*
**      Functions to free memory allocation
**      as_free.c
*/

int		as_free(t_list_byte **list);
int		as_free_error(t_list_error **list);
int		as_free_lab_fla(t_list_label **list, t_flags *flags);
int		as_free_line(char *line);

/*
**      Functions to print error/warning messages on stderr
**      as_error_print.c
**      as_error_print1.c
**      as_error_print2.c
**      as_error_print3.c
**      as_error_print4.c
**      as_error_print.5c
*/

void	as_errnbr(int n);
int		as_print_error(t_list_error **error, t_list_label **label, t_flags *f);
int		as_war1(char *message, int line_nr, char *line, int column_nr);
int		as_err1(char *message, int line_nr, char *line, int column_nr);
int		as_err2(char *message, char *filename);
int		as_err3(char *message);
int		as_malloc_error1(t_list_error **error, int a);
int		as_malloc_error2(t_list_byte **code, int a);
void	as_write_err_line(char *line, int column_nr);
void	as_write_err_sign(char *line, int column_nr);
int		as_write_err(char *message, int line_nr, int column_nr, int e);
int		as_note_cmd(int line_nr, char *line, int column_nr);
int		as_note_reg(int line_nr, int column_nr);
int		as_note_type(int line_nr, int column_nr, char *message);
int		as_note_label(int line_nr, int column_nr, char *message);
void	as_label_error(char *message, int lnr, char *line, int cnr);
int		as_writing_error(t_list_byte **code, char *nn);

/*
**      Functions to store errors before printing them
**      as_error.c
**      as_error1.c
**      as_error2.c
**      as_error3.c
**      as_error4.c
*/

int		as_add_error(t_list_error **err, char *message, char *l, int cnr);
int		as_add_warning(t_list_error **err, char *message, char *l, int cnr);
int		as_add_warning2(t_list_error **err, char *message, char *l, int cnr);
int		as_ant(t_list_error **err, char *message, char *l, int cnr);
int		as_add_label_error(t_list_error **err, char *l, int cnr, int j);
int		as_add_error_noline(t_list_error **err, char *message);
int		as_add_note_cmd(t_list_error **err, char *message, char *l, int cnr);
int		as_add_note_reg(t_list_error **err, char *message, char *l, int cnr);
char	*as_get_err_par(int co, int k);
char	*as_param_error(int a, int b, t_list_error **error);
void	as_del_label_errors(t_list_error **error, char *line, int i);
char	*as_label_sug(char *str, t_list_label *label);
int		as_add_note(t_list_error **error, char *message, int cnr);

/*
**      Functions to check for errors
**      as_error_check.c
**      as_error_check2.c
**      as_error_check3.c
**      as_error_check4.c
**      as_error_check5.c
*/

int		as_ec(char **line, t_list_error **error, int bc);
int		as_lc(char *line, char *filename);
int		as_empty_line_check(t_list_error **error, int a, char *line);
int		as_unexp_check(t_list_error **error, char *line);
int		as_check_enough_params(t_list_error **error, char *line, int i);
int		as_check_valid_params(t_list_error **error, char *line);
int		as_name_check(int *i, char *line, t_list_error **error, int *bc);
int		as_comment_check(int *i, char *line, t_list_error **error, int *bc);
int		as_check_spaces_line(char *line, t_list_error **error);
int		as_check_max_length(char *line, t_list_error **error);
int		as_type_e(int co, int k, int a);
int		as_check_quot(int *i, t_list_error **err, char *line, char *message);
int		as_set_nline_c(int *i, t_list_error **error, char *line, int *comment);
int		as_set_nline_n(int *i, t_list_error **error, char *line, int *comment);
int		as_ccheck1(char *line, int *i, int *j, t_list_error **error);
int		as_ncheck1(char *line, int *i, int *j, t_list_error **error);
int		as_clength_e(int length, t_list_error **error, char *line, int *i);
int		as_nlength_e(int length, t_list_error **error, char *line, int *i);
int		as_c_end(int length, t_list_error **error, char *line, int *i);
int		as_n_end(int length, t_list_error **error, char *line, int *i);

/*
**      Functions to check for errors in parameters
**      indirect:   as_i_error.c
**      direct:     as_d_error.c
**      registers:  as_r_error.c
*/

int		as_i_e(char *line, int *i, t_list_error **error, int *params_size);
int		as_d_e(char *line, int *i, t_list_error **error, int *params_size);
int		as_r_e(char *line, int *i, t_list_error **error, int *params_size);

/*
**      Functions to keep track of error display info
**      as_error_tracking.c
**      as_error_tracking2.c
*/

int		as_line_nr(int a);
int		as_i(int value, int a);
int		as_j(int a, int i);
int		as_k(int a);
int		as_get_pos(unsigned char byte, int a);
int		as_empty_line(int a);
int		as_endcomment(char *line, int a);
int		as_length_e(int a);

/*
**      Functions to initialize function variables
**      as_init.c
**      as_init2.c
*/

int		as_parse_init(char **l, t_list_error **e, int *bc);
int		as_store_init(char **l, t_list_byte **c, t_list_byte **s, int *sec);
void	as_store_name_comment_init(char *line, int *i, int section, int *len);
int		as_gparams_init(int *i, t_list_byte **code, char *l, t_list_byte **enc);
int		as_pparams_init(int *i, char *line, int *params_size);
void	as_ccheck_init(int *bc, int *i, int *j, char *line);
void	as_ncheck_init(int *bc, int *i, int *j, char *line);

/*
**      Functions to parse file
**      as_parse.c
**      as_parse2.c
**      as_parse3.c
*/

int		as_pp_loop(char *l, t_list_label **lab, t_list_error **err, int *ps);
int		as_p_ops(char *l, t_list_error **err, t_list_label **label, int *bc);
int		as_pname(char *line, int *section, t_list_error **error, int *bc);
int		as_pcomment(char *line, int *section, t_list_error **error, int *bc);
int		as_parse_loop(char *l, t_list_error **err, t_list_label **lab, int *bc);
int		as_dlab_e(char *line, t_list_label **label, t_list_error **error);
int		as_lab_e(int j, char *line, t_list_error **err, t_list_label **lab);

/*
**      Functions to skip certain areas in string in parsing
**      as_skip.c
**      as_skip2.c
*/

int		as_skip_space(char *line, int *i);
int		as_skip_label(char *line, int *i);
int		as_skip_label2(char *line, int *i);
int		as_skip_command(char *line, int *i);
int		as_skip_name(char *line, int *i, int *j);
int		as_skip_rev_space(char *line, int *i);
int		as_skip_to_params(char *line, int *i);
int		as_skip_to_sep(char *line, int *i);
int		as_skip_to_next_param(char *line, t_list_error **error, int *i);
void	as_lab_skip(char *line, int *j, char *c);

/*
**      Functions to display and save output
**      as_output.c
**      as_output2.c
**      as_output3.c
*/

int		as_wfile(t_list_byte **code, char *filename);
int		as_plist(t_list_byte *list);
int		as_pa(t_flags *f, t_list_byte **c, t_list_byte *e, t_list_byte **o);
void	as_write_byte(t_list_byte *code);
int		as_flags_loop(t_flags **flags, int argc, char **argv, int *pos);
void	as_a_line(t_flags *f, int sec, t_list_byte *code, char *line);

/*
**      General utility functions
**      as_utility.c
**      as_utility2.c
*/

int		as_code_size(t_list_byte *code);
int		as_reverse_error(t_list_error **list);
int		as_rlist(t_list_byte **list);
int		as_label_list_size(t_list_label *label);
int		as_get_op_pos(char *line, int i);
void	as_write_bytes(t_list_byte **code, int info, int n);
int		as_add_bytes(t_list_byte **code, int n, int type);
int		as_add_byte(t_list_byte **code, unsigned char byte, int type);
int		as_cmd_comp(char *cmd, char *str);
int		as_add_label(t_list_label **label, char *line, int i, int pos);

#endif
