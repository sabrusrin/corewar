/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:20:09 by chermist          #+#    #+#             */
/*   Updated: 2020/07/01 20:00:04 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "libft.h"

# include "op.h"

# define TRUE 1
# define FALSE 0

typedef enum
{
	COMMAND,
	STRING,
	SEPARATOR,
	DIRECT,
	DIRECT_LABEL,
	LABEL,
	INDIRECT_LABEL,
	INSTRUCTION,
	REGISTER
} t_type;

typedef struct		s_response
{
	char			*error;
	void			*data;
}					t_response;

typedef struct		s_parser
{
	int				line;	
	int				col;
	int				fd;
	char			*name;
	char			*comment;
	char			*byte_code;
	t_token			*token;
	t_vec			*buffer;
	t_vec			*tokens;
}					t_parser;

typedef struct		s_token
{
	int				line;
	int				col;
	t_type			type;
	char			*content;
}					t_token;

int					assemble(const char *filename);
void				tokenize(t_parser *parse_struct);
t_token				*token_create(t_parser *parse_struct, t_type type, \
																char *content);
void				label_instr_reg_token_create(t_parser *parse_struct, \
															char **carriage);
void				separator_token_create(t_parser *parse_struct, \
															char **carriage);
void				direct_label_token_create(t_parser *parse_struct, \
															char **carriage);
void				direct_token_create(t_parser *parse_struct, \
															char **carriage);

/*
** helper functions
*/
int					check_filename(const char *filename, const char *suffix);
void				throw_error(char *err);
void				throw_error_tokenizing(char *err, int line, int col);
int					string_len(char **carriage, char delim);
void				comment_skip(t_parser *parse_struct, char **carriage);

/*
** initialize function initializes t_parser struct
*/
t_parser			*initialize(const char *filename);

#endif