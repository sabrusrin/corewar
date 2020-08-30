/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:42:55 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 22:50:23 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int	apply(t_vm *v, t_plist *list)
{
	t_param	*param_tab;
	int		ret;

	if (!(param_tab = (t_param*)malloc(sizeof(t_param) * 3)))
		return (exit_fail(v, NULL, 1));
	if (list->proc.opc < 0)
		return (exit_fail(v, param_tab, 1));
	param_setup(v, &(list->proc), param_tab);
	check_error(v, &list->proc, param_tab);
	if (v->verbose & 4 && list->proc.error == 0)
		print_op_exec(v, list, param_tab);
	if (list->proc.opc == 15 || list->proc.opc == 12)
		ret = (*v->op_fn[list->proc.opc - 1])(v, &list->proc, param_tab);
	else
		ret = (*v->op_fn[list->proc.opc - 1])(v, &list->proc, param_tab);
	list->proc.opc = 0;
	free(param_tab);
	return (ret);
}

static void	print_moves(t_vm *v, t_plist *tmp, unsigned int old_pc)
{
	int				i;
	int				new_pc;
	int				swap;

	swap = old_pc;
	new_pc = tmp->proc.pc;
	if (old_pc > tmp->proc.pc)
	{
		old_pc = tmp->proc.pc;
		new_pc = swap;
	}
	ft_printf("ADV %d (%#06x -> %#06x) ",
		new_pc - old_pc, old_pc, new_pc);
	i = 0;
	while (vm_abs((old_pc - new_pc)) - i)
	{
		ft_printf("%02x ", (unsigned char)v->f.field[get_offset(swap + i)]);
		i++;
	}
	ft_putchar('\n');
}

void		set_unset(t_vm *v, t_plist *tmp)
{
	if (tmp->proc.proc_nb && tmp->proc.opc == -2)
	{
		tmp->proc.opc = v->f.field[tmp->proc.pc];
		if (tmp->proc.opc <= 16 && tmp->proc.opc > 0)
			tmp->proc.exec_cycle = v->curr_cycle +
				v->op_tab[tmp->proc.opc - 1].cycles - 1;
		else
			tmp->proc.opc = 0;
	}
	if ((tmp->proc.opc == 0 && tmp->proc.proc_nb))
	{
		tmp->proc.pc = get_offset(tmp->proc.pc + 1);
		tmp->proc.opc = -2;
	}
}

void		execute_cycle(t_vm *v, t_plist *tmp)
{
	unsigned int	old_pc;

	if (tmp->proc.exec_cycle == v->curr_cycle && tmp->proc.opc > 0)
	{
		old_pc = tmp->proc.pc;
		tmp->proc.pc += apply(v, tmp);
		if (v->verbose & 16 && (v->f.field[old_pc] != 9 || !tmp->proc.carry))
			print_moves(v, tmp, old_pc);
		tmp->proc.pc = get_offset(tmp->proc.pc);
		tmp->proc.error = 0;
		tmp->proc.exec_cycle = 0;
		tmp->proc.opc = -1;
	}
}

void		exec_catcher(t_vm *v, t_plist *tmp)
{
	if (tmp->proc.opc == -1 && tmp->proc.proc_nb)
	{
		tmp->proc.opc = v->f.field[tmp->proc.pc];
		if (tmp->proc.opc <= 16 && tmp->proc.opc > 0)
			tmp->proc.exec_cycle = v->curr_cycle +
				v->op_tab[tmp->proc.opc - 1].cycles;
		else
			tmp->proc.opc = 0;
	}
}
