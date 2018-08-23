/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <jszabo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:20:40 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 15:01:07 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AS_ERRORS_H
# define AS_ERRORS_H

# define MAX_LINE_LENGTH 1000
# define MAX_LINE_NUM 500
# define MAX_ERROR_SIZE 40
# define LABEL_SIZE 20
# define D_LENGTH_CHECK 0
# define I_LENGTH_CHECK 0
# define U1      "./asm [-w -W -p -a] <sourcefile.s> \n"
# define U2      "    -w : Disables warnings\n"
# define U3      "    -W : Displays warnings about improper spaces\n"
# define U4      "    -p : Displays the compiled machine code, color-coded\n"
# define U5      "    -a : Displays an annotated version of the code\n"
# define USAGE       U1 U2 U3 U4 U5
# define ERROR1      " name specifier string incorrect\n"
# define ERROR2      " missing quotation mark before name\n"
# define ERROR4      " unnecessary separator character after last parameter\n"
# define ERROR5      " missing quotation mark before comment\n"
# define ERROR7      " comment specifier string incorrect\n"
# define ERROR8      " unknown operation\n"
# define ERROR9      " missing parameters\n"
# define ERROR10      " label too long\n"
# define ERROR11      " invalid parameter\n"
# define ERROR12      " register number missing from parameter\n"
# define ERROR13      " register doesn't exist\n"
# define ERROR15      " incompatible parameter\n"
# define ERROR16      " too many parameters for this type of operation\n"
# define ERROR17      " line exceeds maximum length\n"
# define ERROR18      " too few parameters for operation, expected "
# define ERROR18B     ", have "
# define ERROR20      " invalid characters at the end of parameter\n"
# define ERROR22      " missing label\n"
# define ERROR23      " invalid label\n"
# define ERROR24      " duplicate label\n"
# define ERROR25      " direct reference missing from parameter\n"
# define ERROR26      " direct reference number is too long\n"
# define ERROR28      " label reference not found\n"
# define ERROR29      " source file incomplete\n"
# define ERROR30      "no such file: "
# define ERROR31      "not a valid source file: "
# define ERROR32      " compiled size would exceed maximum length\n"
# define ERROR33      " file ends unexpectedly\n"
# define ERROR34      "could not close file due to an error: "
# define ERROR35      " no valid code in file\n"
# define ERROR36      " file couldn't be created: "
# define ERROR37      " line number exceeds maximum\n"
# define WARNING1    " no space after name specifier\n"
# define WARNING2    " invalid character(s) after name\n"
# define WARNING3    " name too long\n"
# define WARNING4    " no space after comment specifier\n"
# define WARNING5    " missing comment\n"
# define WARNING6    " invalid character(s) after comment\n"
# define WARNING7    " comment too long\n"
# define WARNING8    " space before argument separator\n"
# define WARNING9    " unnecessary space before parameter\n"
# define WARNING10    " space at the end of the line\n"
# define WARNING11    " unnecessary spaces between operation and parameter\n"
# define WARNING12    " indirect reference too far\n"
# define WARNING13    " unnecessary empty lines\n"
# define WARNING14    " unnecessary empty lines at the end of the file\n"
# define WARNING15    " unnecessary spaces at the end of the line\n"
# define WARNING16    " line only consists of unnecessary spaces\n"
# define WARNING17    " unnecessary spaces before name specifier\n"
# define WARNING18    " unnecessary spaces before comment specifier\n"
# define WARNING19    " missing name\n"
# define NOTE1        " file should end with a single new line\n"

#endif
