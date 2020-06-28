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

typedef unsigned char uchar;
typedef unsigned int uint;

/*
** structure with variables
*/

typedef	struct	s_var
{
	uchar	a1;
	short	a2;
	uint	a4;
	int		fd;
	int		r;
	uchar	opc;
	uchar	ops_size;
	uint	tmp; //for reading nulls and champ size
	uint	champ_size;
	uchar	bt; //bytes for a given argument
}				t_var;

/*
** fun_print.c
*/

uint			reverseBits(uint num);
uint 			reverse_byte_by_byte_int(uint num);
short 			reverse_byte_by_byte_short(short num);
void			print_binary_uint(uint n);
void			print_binary_uchar(uchar n);
t_bool			free_line(char **line, t_bool ret);

/*
** fun_read.c
*/

t_bool			read_magic_header(t_var *v);
void			read_champ_name(t_var *v, t_header *f);
t_bool			read_null(t_var *v);
t_bool			read_champ_size(t_var *v);
void			read_champ_comment(t_var *v, t_header *f);

//not categorized

t_bool	check_files_names(int argc, char **argv);
uchar	arg_byte(uchar opc, uchar arg);
void	read_argument(t_var *v, uchar arg, t_bool comma);


t_bool	read_instruction(t_var *v);
t_bool	read_s_file(t_var *v, t_header *f);
t_bool	open_close_s_file(int argc, char **argv, t_header *f);


#endif

//clang test_disassembly.c op.c -lft -L ../../libft/ -I ../inc/ -I ../../libft/includes/
//gcc test_disassembly.c  -I ../inc/ -I ../../libft/includes/ ../../libft/libft.a

//gcc test_disassembly.c op.c fun_print.c fun_read.c  -I ../inc/ -I ../../libft/includes/ ../../libft/libft.a
