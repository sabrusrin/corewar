/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:29:45 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 22:48:25 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static void		check_param_code(t_vm *v, t_process *p, t_param *param_tab)
{
	int		i;
	t_op	op;

	i = -1;
	op = v->op_tab[p->opc - 1];
	while (++i < op.nb_params)
	{
		if ((unsigned char)v->f.field[get_offset(p->pc + 1)] < 40
			|| (unsigned char)v->f.field[get_offset(p->pc + 1)] > 244)
			p->error = 2;
		else if (param_tab[i].direct && !(op.params[i] & T_DIR))
			p->error = 1;
		else if (param_tab[i].indirect && !(op.params[i] & T_IND))
			p->error = 1;
		else if (param_tab[i].reg && !(op.params[i] & T_REG))
			p->error = 1;
		else if (!(param_tab[i].reg + param_tab[i].direct
					+ param_tab[i].indirect))
			p->error = 1;
	}
}

static int		init_bit(t_vm *v, t_process *p, t_param *param_tab, int c)
{
	int		bit;

	ft_bzero(&param_tab[c], sizeof(t_param));
	if (p->opc != 9 && p->opc != 15 && p->opc != 1 && p->opc != 12)
		bit = (v->f.field[get_offset(p->pc + 1)] << (2 * c)) & 0xC0;
	else
		bit = 0;
	return (bit);
}

static int		direct_bit(t_vm *v, t_process *p, t_param *param, int pos)
{
	param->direct = 1;
	if (v->op_tab[p->opc - 1].size)
	{
		param->val = read_ind(v, pos, T_DIR / 2);
		return (T_DIR / 2);
	}
	else
	{
		param->val = read_ind(v, pos, T_DIR);
		return (T_DIR);
	}
}

static void		param_setup_loop(t_vm *v, t_process *p, t_param *param_tab,
		int offset)
{
	int		c;
	int		bit;
	int		pos;

	c = -1;
	while (++c < v->op_tab[p->opc - 1].nb_params)
	{
		bit = init_bit(v, p, param_tab, c);
		pos = get_offset(p->pc + offset);
		if (bit == 0xC0)
		{
			param_tab[c].indirect = 1;
			param_tab[c].val = read_ind(v, pos, T_IND);
			offset += T_IND;
		}
		else if (bit == 0x80 || p->opc == 9 || p->opc == 12 || p->opc == 1
				|| p->opc == 15)
			offset += direct_bit(v, p, &param_tab[c], pos);
		else if (bit == 0x40)
		{
			param_tab[c].reg = 1;
			param_tab[c].val = v->f.field[get_offset(p->pc + offset)];
			offset += T_REG;
		}
	}
}

void			param_setup(t_vm *v, t_process *p, t_param *param_tab)
{
	int		offset;

	if (p->opc != 9 && p->opc != 15 && p->opc != 1 && p->opc != 12)
		offset = 2;
	else
		offset = 1;
	param_setup_loop(v, p, param_tab, offset);
	if (p->opc != 9 && p->opc != 15 && p->opc != 1 && p->opc != 12)
		check_param_code(v, p, param_tab);
}
