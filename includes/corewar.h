/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:11:02 by adavis            #+#    #+#             */
/*   Updated: 2020/08/10 23:30:46 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"

# define MODULO			1 //
# define TWO_BYTES		2
# define READ			4
# define REG			8 //
# define REG_R			16 //

typedef struct		s_memcell {
	unsigned char	value;
	int				champ_id;
}					t_memcell;

// typedef struct		s_champ {
// 	char			*name;
// 	char			*comment;
// 	int				size;
// 	int				fd;
// 	int				n;
// }					t_champ;

typedef struct			s_champ
{
	int					nb_champ;
	t_header			head;
	char				prog[CHAMP_MAX_SIZE];
	int					count_live;
}						t_champ;

typedef struct			s_process
{
	int					proc_nb;
	int					exec_cycle;
	int					last_turn_alive;
	int					reg[REG_NUMBER];
	int					opc;
	unsigned int		pc;
	char				carry;
	int					alive;
	int					champ;
	int					error;
}						t_process;

typedef	struct			s_param
{
	int					direct;
	int					indirect;
	int					reg;
	int					val;
}						t_param;

typedef struct			s_plist
{
	t_process			proc;
	struct s_plist		*next;
	struct s_plist		*prev;
}						t_plist;

typedef struct			s_field
{
	char				field[MEM_SIZE];
	char				owner[MEM_SIZE];
}						t_field;

typedef struct			s_op
{
	char				*name;
	int					nb_params;
	int					params[3];
	int					opcode;
	int					cycles;
	char				*description;
	int					carry;
	int					size;
}						t_op;

typedef struct			s_vm
{
	t_field				f;
	t_plist				*process_list;
	t_champ				players[MAX_PLAYERS];
	t_op				op_tab[17];
	int					(*op_fn[17])();
	char				*op_descriptions[17];
	int					nb_players;
	int					last_p_alive;
	int					curr_cycle;
	int					kill_cycle;
	int					kill_check;
	int					nb_lives;
	int					verbose;
	int					cycle_to_die;
	int					curr_alive;
	int					dump_cycle;
	int					dirty;
	int					nb_process;
	int					nb_proc_alive;
	char				print_cycles_to_die;
	int					visu;
}						t_vm;

typedef struct		s_head
{
	int				id;				// id каретки
	int				champ_id;		// id чемпиона
	char			carry;			// флаг carry
	int				op_code;		// код операции, на которой стоит каретка
	int				last_live;		// номер цикла последнего выполнения live
	int				to_op;			// количество циклов до выполнения операции
	int				pos;			// текущая позиция
	int				to_next;		// сколько байт пройти к следующей операции
	unsigned int	*regs;			// регистры
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


typedef struct			s_parse_argv
{
	int					i;
	int					count_champ;
	int					is_verbose;
	int					is_dump;
	int					is_nb;
	int					nb_champ;
	int					count_nb;
	int					bool;
	int					is_visu;
}						t_parse_argv;

typedef struct			s_type_argv
{
	char				*str;
	int					(*f)(int argc, char **argv, t_parse_argv *av, t_vm *v);
}						t_type_argv;

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

t_champ				*args_parse(int ac, char **av);



int						ft_number(int argc, char **argv, t_parse_argv *av);
int						wrapper(void *p, char return_error_flag);
int						ft_argv(t_vm *v, int argc, char **argv);
int16_t					reverser_16(int16_t a);
int32_t					reverser_32(int32_t a);
int						read_ind(t_vm *v, int pos, int size);
void					write_ind(char mem[], int pos, int val, int size);
void					write_ind_owner(char mem[], int pos, int val, int size);
int						ft_usage(void);
int						ft_init_champ(int argc, char **argv, t_parse_argv *av,
						t_vm *v);
void					init_op_table(t_vm *v);
int						operate(t_vm *vm);
void					print_op_exec(t_vm *v, t_plist *list,
						t_param *param_tab);
void					exec_catcher(t_vm *v, t_plist *tmp);
void					execute_cycle(t_vm *v, t_plist *tmp);
void					set_unset(t_vm *v, t_plist *tmp);
int						pre_op(t_vm *v, t_process *proc, t_param *params,
						char options);
int						get_offset(int offset);
void					check_error(t_vm *v, t_process *proc,
						t_param *param_tab);
int						op_live(t_vm *v, t_process *proc, t_param *params);
int						op_ld(t_vm *v, t_process *proc, t_param *params);
int						op_st(t_vm *v, t_process *proc, t_param *params);
int						op_add(t_vm *v, t_process *proc, t_param *params);
int						op_sub(t_vm *v, t_process *proc, t_param *params);
int						op_and(t_vm *v, t_process *proc, t_param *params);
int						op_or(t_vm *v, t_process *proc, t_param *params);
int						op_xor(t_vm *v, t_process *proc, t_param *params);
int						op_zjmp(t_vm *v, t_process *proc, t_param *params);
int						op_ldi(t_vm *v, t_process *proc, t_param *params);
int						op_sti(t_vm *v, t_process *proc, t_param *params);
int						op_fork(t_vm *v, t_process *proc, t_param *params);
int						op_lld(t_vm *v, t_process *proc, t_param *params);
int						op_lldi(t_vm *v, t_process *proc, t_param *params);
int						op_lfork(t_vm *v, t_process *proc, t_param *params);
int						op_aff(t_vm *v, t_process *proc, t_param *params);
void					cycles_to_die(t_vm *v);
void					count_alive(t_vm *v, int reset);
int						load_field(t_vm *v);
int						start_proc_list(t_vm *v);
void					param_setup(t_vm *v, t_process *p, t_param *param_tab);
char					*ft_convert_hexa(unsigned char n);
int						ft_dump(t_vm *v);
void					intro(t_vm *v);
int						verbose(int argc, char **argv, t_parse_argv *av,
						t_vm *v);
int						dump(int argc, char **argv, t_parse_argv *av, t_vm *v);
int						dirty(int argc, char **argv, t_parse_argv *av, t_vm *v);
int						num_champ(int argc, char **argv, t_parse_argv *av,
						t_vm *v);
int						init_visu(int argc, char **argv, t_parse_argv *av,
						t_vm *v);
int						champ(int argc, char **argv, t_parse_argv *av, t_vm *v);
int						update_turn(t_vm *v);
int						render_win(t_vm *v);
void					free_proc_list(t_vm *v);
int						exit_fail(t_vm *v, t_param *param_tab,
						int free_ist);
int32_t					vm_abs(int n);
int						helper(t_vm *v, t_process p, t_param param, int mod);

#endif
