/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:19:34 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/16 20:11:57 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "corewar.h"

int		op_sti(t_vm *v, t_process *proc, t_param *params)
{
	char	options;
	char	options_two;
	int		step;

	options = TWO_BYTES | READ | REG_R;
	options_two = TWO_BYTES | REG;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], options_two);
	step += pre_op(v, proc, &params[1], options);
	step += pre_op(v, proc, &params[2], options);
	if (proc->error)
		return (step);
	write_ind(v->f.field, proc->pc + (params[1].val + params[2].val) % IDX_MOD,
		params[0].val, REG_SIZE);
	write_ind_owner(v->f.owner, proc->pc + (params[1].val + params[2].val)
		% IDX_MOD, proc->champ, REG_SIZE);
	return (step);
}

int		op_fork(t_vm *v, t_process *proc, t_param *params)
{
	t_plist	*dup;

	if (!(dup = (t_plist*)malloc(sizeof(t_plist))))
		return (exit_fail(v, params, 1));
	ft_memcpy(&dup->proc, proc, sizeof(t_process));
	pre_op(v, proc, &params[0], TWO_BYTES);
	dup->proc.pc = get_offset(dup->proc.pc + params[0].val % IDX_MOD);
	dup->proc.opc = v->f.field[dup->proc.pc];
	if (dup->proc.opc > 0 && dup->proc.opc < 16)
		dup->proc.exec_cycle = v->curr_cycle
			+ v->op_tab[dup->proc.opc - 1].cycles;
	else
		dup->proc.opc = 0;
	dup->proc.proc_nb = ++v->nb_process;
	dup->next = v->process_list;
	dup->proc.error = 0;
	dup->prev = NULL;
	v->process_list->prev = dup;
	v->process_list = dup;
	return (OP + S_IND);
}

int		op_lld(t_vm *v, t_process *proc, t_param *params)
{
	int	step;

	(void)v;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], READ);
	step += pre_op(v, proc, &params[1], 0);
	if (proc->error)
		return (step);
	proc->reg[params[1].val] = params[0].val;
	proc->carry = !params[0].val ? 1 : 0;
	return (step);
}

int		op_lldi(t_vm *v, t_process *proc, t_param *params)
{
	char	options;
	int		step;

	(void)v;
	options = TWO_BYTES | READ;
	step = OP + OCP;
	step += pre_op(v, proc, &params[0], options);
	step += pre_op(v, proc, &params[1], options);
	step += pre_op(v, proc, &params[2], options);
	if (proc->error)
		return (step);
	proc->reg[params[2].val] = reverser_32(read_ind(v, proc->pc
		+ params[0].val + params[1].val, REG_SIZE));
	proc->carry = !proc->reg[params[2].val] ? 1 : 0;
	return (step);
}

int		op_lfork(t_vm *v, t_process *proc, t_param *params, t_visu *sdl)
{
	t_plist	*dup;

	if (!(dup = (t_plist*)malloc(sizeof(t_plist))))
		return (exit_fail(v, sdl, params, 1));
	ft_memcpy(&dup->proc, proc, sizeof(t_process));
	pre_op(v, proc, &params[0], TWO_BYTES);
	dup->proc.pc = get_offset(dup->proc.pc + params[0].val);
	dup->proc.opc = v->f.field[dup->proc.pc];
	if (dup->proc.opc > 0 && dup->proc.opc < 16)
		dup->proc.exec_cycle = v->curr_cycle
			+ v->op_tab[dup->proc.opc - 1].cycles;
	else
		dup->proc.opc = 0;
	dup->proc.proc_nb = ++v->nb_process;
	dup->next = v->process_list;
	dup->proc.error = 0;
	dup->prev = NULL;
	v->process_list->prev = dup;
	v->process_list = dup;
	return (OP + S_IND);
}
