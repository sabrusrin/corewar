/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:11:02 by adavis            #+#    #+#             */
/*   Updated: 2019/12/07 15:12:55 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"

typedef struct		s_memcell {
	unsigned char	value;
	int				champ_id;
}					t_memcell;

typedef struct		s_champ {
	char			*name;
	char			*comment;
	int				size;
	int				fd;
	int				n;
}					t_champ;

typedef struct		s_head
{
	int				id;
	int				champ_id;
	char			carry;
	int				op_code;
	int				last_live;
	int				to_op;
	int				pos;
	int				to_next;
	unsigned int	*regs;
	struct s_head	*next;
}					t_head;

typedef struct 		s_corewar
{
	t_memcell		*arena;
	t_champ			*champs;
	t_head			*heads;
	int				champs_cnt;
	int				last_alive_id;
	int				cycles_passed;
	int				live_in_cycle;
	int				cycles_to_die;
	int				checks;
}					t_corewar;

/*
**	Arena methods (arena.c)
*/
int					arena_init(t_corewar *cw);
void				arena_print(t_corewar *cw);

/*
**	Memcell methods (memcell.c)
*/
void				memcell_set(t_corewar *cw, int i, int value, int champ_id);

/*
**	Champs methods (champs.c)
*/
int					champs_init(t_corewar *cw, int ac, char **av);
int					champs_load(t_corewar *cw);
int					champs_greet(t_corewar *cw);

/*
**	Hex files methods (hex.c)
*/
char				*hex_get_string(int fd, int size);
int					hex_check_null(int fd);
int					hex_get_nbr(int fd, int size);

/*
**	Heads methods (heads.c)
*/
int					heads_init(t_corewar *cw);
void				heads_print(t_corewar *cw);

/*
**	Exit methods (exit.c)
*/
void				exit_null_block();
void				exit_header();
void				exit_open(char *file);

void				cycle(t_corewar *cw);

int					args_parse(int ac, char **av);

#endif
