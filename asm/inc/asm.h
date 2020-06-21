/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:20:09 by chermist          #+#    #+#             */
/*   Updated: 2020/06/21 22:01:38 by chermist         ###   ########.fr       */
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
	unsigned char	op_code;
	char			*type;
	char			*content;
}					t_token;

int					assemble(const char *filename);

/*
** helper functions
*/
int					check_filename(const char *filename, const char *suffix);
void				throw_error(char *err);

/*
** initialize function initializes t_parser struct
*/
t_parser			*initialize(const char *filename);

#endif