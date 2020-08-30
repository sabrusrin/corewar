/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:44:52 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/02 19:17:22 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "corewar.h"

int		op_live(t_vm *v, t_process *proc, t_param *params)
{
	int		i;
	int		step;

	i = -1;
	step = OP;
	step += pre_op(v, proc, &params[0], 0);
	if (proc->error)
		return (step);
	while (++i < v->nb_players)
		if (v->players[i].nb_champ == params[0].val)
		{
			if (v->verbose & 1)
				ft_printf("Player %d (%s) is said to be alive\n",
					ft_abs(v->players[i].nb_champ), v->players[i].head.name);
			break ;
		}
	if (i > -1 && i < MAX_PLAYERS)
		v->players[i].count_live++;
	if (i < v->nb_players)
		v->last_p_alive = i;
	proc->last_turn_alive = v->curr_cycle;
	proc->alive++;
	v->nb_lives++;
	return (step);
}

int		op_ld(t_vm *v, t_process *proc, t_param *params)
{
	char	options;
	int		step;

	(void)v;
	options = MODULO | READ;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], options);
	step += pre_op(v, proc, &params[1], 0);
	if (proc->error)
		return (step);
	proc->reg[params[1].val] = params[0].val;
	proc->carry = !params[0].val ? 1 : 0;
	return (step);
}

int		op_st(t_vm *v, t_process *proc, t_param *params)
{
	int		step;

	step = OP + OCP;
	step += pre_op(v, proc, &params[0], 0);
	step += pre_op(v, proc, &params[1], MODULO);
	if (proc->error)
		return (step);
	if (params[1].reg)
		proc->reg[params[1].val] = proc->reg[params[0].val];
	else if (params[1].indirect)
	{
		write_ind(v->f.field, params[1].val,
			reverser_32(proc->reg[params[0].val]), REG_SIZE);
		write_ind_owner(v->f.owner, params[1].val, proc->champ, REG_SIZE);
	}
	return (step);
}

int		op_add(t_vm *v, t_process *proc, t_param *params)
{
	int		step;

	(void)v;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], 0);
	step += pre_op(v, proc, &params[1], 0);
	step += pre_op(v, proc, &params[2], 0);
	if (proc->error)
		return (step);
	proc->reg[params[2].val] = proc->reg[params[0].val]
		+ proc->reg[params[1].val];
	proc->carry = !proc->reg[params[2].val] ? 1 : 0;
	return (step);
}

int		op_sub(t_vm *v, t_process *proc, t_param *params)
{
	int		step;

	(void)v;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], 0);
	step += pre_op(v, proc, &params[1], 0);
	step += pre_op(v, proc, &params[2], 0);
	if (proc->error)
		return (step);
	proc->reg[params[2].val] = proc->reg[params[0].val]
		- proc->reg[params[1].val];
	proc->carry = !proc->reg[params[2].val] ? 1 : 0;
	return (step);
}
