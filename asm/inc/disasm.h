/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:35:38 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/19 00:04:39 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H
# include <fcntl.h>
# include "asm.h"

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef	unsigned char	t_uchar;
typedef	unsigned short	t_ushort;
typedef unsigned int	t_uint;

/*
** structure with variables
** a1 for reading uchar
** a2 for reading short
** a4 for reading uint
** fd is file descriptor
** r is number of read bytes
** opc is operation (live, st, ld, ...)
** tmp is temprorary for reading nulls
** bt is number of bytes for a given argument
*/

typedef	struct	s_var
{
	t_uchar		a1;
	short		a2;
	t_uint		a4;
	int			fd;
	int			r;
	t_uchar		opc;
	t_uchar		ops_size;
	t_uint		tmp;
	t_uint		champ_size;
	t_uchar		bt;
}				t_var;

/*
** fun_print.c
*/

t_uint			reverse_byte_by_byte_int(t_uint num);
short			reverse_byte_by_byte_short(short num);
t_ushort	reverse_byte_by_byte_short(t_ushort num);

void			print_binary_uint(t_uint n);
void			print_binary_uchar(t_uchar n);
void			print_binary_short(short n);

/*
** fun_read1.c
*/

t_bool			read_size(t_var *v);
t_bool			read_instruction(t_var *v);
t_bool			read_s_file(t_var *v, t_header *f);
t_bool			open_close_s_file(int argc, char **argv, t_header *f);

/*
** fun_read2.c
*/

t_bool			check_files_names(int argc, char **argv);
t_uchar			arg_byte(t_uchar opc, t_uchar arg);
void			read_argument_2_4_bytes(t_var *v);
void			read_argument(t_var *v, t_uchar arg, t_bool comma);

/*
** fun_read2.c
*/

t_bool			read_magic_header(t_var *v);
void			read_champ_name(t_var *v, t_header *f);
t_bool			read_null(t_var *v);
t_bool			read_champ_size(t_var *v);
void			read_champ_comment(t_var *v, t_header *f);
#endif
