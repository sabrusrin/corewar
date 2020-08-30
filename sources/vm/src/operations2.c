/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:16:59 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/16 20:10:37 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		op_and(t_vm *v, t_process *proc, t_param *params)
{
	char	options;
	int		step;

	(void)v;
	options = READ | REG_R;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], options);
	step += pre_op(v, proc, &params[1], options);
	step += pre_op(v, proc, &params[2], 0);
	if (proc->error)
		return (step);
	proc->reg[params[2].val] = params[0].val & params[1].val;
	proc->carry = !proc->reg[params[2].val] ? 1 : 0;
	return (step);
}

int		op_or(t_vm *v, t_process *proc, t_param *params)
{
	char	options;
	int		step;

	(void)v;
	options = READ | REG_R;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], options);
	step += pre_op(v, proc, &params[1], options);
	step += pre_op(v, proc, &params[2], 0);
	if (proc->error)
		return (step);
	proc->reg[params[2].val] = params[0].val | params[1].val;
	proc->carry = !proc->reg[params[2].val] ? 1 : 0;
	return (step);
}

int		op_xor(t_vm *v, t_process *proc, t_param *params)
{
	char	options;
	int		step;

	(void)v;
	options = READ | REG_R;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], options);
	step += pre_op(v, proc, &params[1], options);
	step += pre_op(v, proc, &params[2], 0);
	if (proc->error)
		return (step);
	proc->reg[params[2].val] = params[0].val ^ params[1].val;
	proc->carry = !proc->reg[params[2].val] ? 1 : 0;
	return (step);
}

int		op_zjmp(t_vm *v, t_process *proc, t_param *params)
{
	(void)v;
	if (proc->carry)
	{
		pre_op(v, proc, &params[0], TWO_BYTES);
		if (proc->error)
			return (0);
		proc->pc = get_offset(proc->pc + params[0].val % IDX_MOD);
		return (0);
	}
	return (OP + S_IND);
}

int		op_ldi(t_vm *v, t_process *proc, t_param *params)
{
	char	options;
	int		step;

	(void)v;
	options = TWO_BYTES | READ | REG_R;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], options);
	step += pre_op(v, proc, &params[1], options);
	step += pre_op(v, proc, &params[2], TWO_BYTES);
	if (proc->error)
		return (step);
	proc->reg[params[2].val] = reverser_32(read_ind(v, proc->pc
		+ (params[0].val + params[1].val) % IDX_MOD, REG_SIZE));
	return (step);
}
