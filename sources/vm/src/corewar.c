/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:15:17 by adavis            #+#    #+#             */
/*   Updated: 2020/08/10 23:22:49 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_op_fn(t_vm *v)
{
	v->op_fn[0] = op_live;
	v->op_fn[1] = op_ld;
	v->op_fn[2] = op_st;
	v->op_fn[3] = op_add;
	v->op_fn[4] = op_sub;
	v->op_fn[5] = op_and;
	v->op_fn[6] = op_or;
	v->op_fn[7] = op_xor;
	v->op_fn[8] = op_zjmp;
	v->op_fn[9] = op_ldi;
	v->op_fn[10] = op_sti;
	v->op_fn[11] = op_fork;
	v->op_fn[12] = op_lld;
	v->op_fn[13] = op_lldi;
	v->op_fn[14] = op_lfork;
	v->op_fn[15] = op_aff;
	v->op_fn[16] = 0;
}

static void	init_vm(t_vm *v)
{
	v->verbose = -1;
	v->cycle_to_die = CYCLE_TO_DIE;
	v->kill_cycle = CYCLE_TO_DIE;
	v->kill_check = 0;
	v->nb_lives = 0;
	v->process_list = NULL;
	v->curr_cycle = 1;
	v->dump_cycle = -1;
	init_op_table(v);
	init_op_fn(v);
}

int			main(int argc, char **argv)
{
	t_vm	*v;

	if (!(v = (t_vm*)malloc(sizeof(t_vm))))
		return (0);
	init_vm(v);
	if ((v->nb_players = ft_argv(v, argc, argv)) <= 0)
	{
		free(v);
		return (-1);
	}
	if (v->verbose == -1)
		v->verbose = 0;
	load_field(v);
	operate(v);
	free(v);
	return (0);
}