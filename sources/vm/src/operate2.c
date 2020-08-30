/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:43:08 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 22:34:31 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int	print_params2(t_vm *v, t_process p, t_param *param_tab, int i)
{
	int		tmp;

	if (param_tab[i].indirect)
	{
		tmp = reverser_16((int16_t)param_tab[i].val);
		if (p.opc == 2 || (p.opc >= 6 && p.opc <= 8) || p.opc == 10
			|| p.opc == 11 || p.opc == 14 || p.opc == 13)
		{
			tmp = (p.pc + tmp % IDX_MOD) % MEM_SIZE;
			tmp = reverser_32(read_ind(v, tmp, IND_SIZE));
			ft_putnbr(tmp);
		}
		else
			ft_putnbr(tmp);
		return (1);
	}
	else if (param_tab[i].reg && ((((p.opc >= 6 && p.opc <= 8)
		|| p.opc == 10) && i != 2) || (p.opc == 11 && i != 0)))
	{
		ft_putnbr(p.reg[param_tab[i].val - 1]);
		return (1);
	}
	return (0);
}

static void	print_params(t_vm *v, t_process p, t_param *param_tab)
{
	int		i;
	int		nb_params;

	i = -1;
	nb_params = v->op_tab[p.opc - 1].nb_params;
	while (++i < nb_params)
	{
		if (param_tab[i].reg && (((p.opc < 6 || p.opc > 8) && p.opc != 10
			&& p.opc != 11 && p.opc != 3) || (((p.opc >= 6 && p.opc <= 8)
			|| p.opc == 10) && i == 2) || (p.opc == 11 && i == 0)
			|| (p.opc == 3 && i != 1)))
			ft_putchar('r');
		if (v->op_tab[p.opc - 1].size && param_tab[i].direct)
			ft_putnbr(reverser_16(param_tab[i].val));
		else if (param_tab[i].direct)
			ft_putnbr(reverser_32(param_tab[i].val));
		else if (print_params2(v, p, param_tab, i))
			;
		else
			ft_putnbr(param_tab[i].val);
		if (i + 1 != nb_params)
			ft_putchar(' ');
	}
}

static void	print_op_exec3(t_vm *v, t_plist *list, t_param *param_tab)
{
	if (list->proc.opc == 14)
		ft_printf(" %d + %d = %d (with pc %d)",
			helper(v, list->proc, param_tab[0], 0),
			helper(v, list->proc, param_tab[1], 0),
			helper(v, list->proc, param_tab[1], 0)
			+ helper(v, list->proc, param_tab[0], 0),
			helper(v, list->proc, param_tab[1], 0)
			+ helper(v, list->proc, param_tab[0], 0)
			+ list->proc.pc);
}

static void	print_op_exec2(t_vm *v, t_plist *list, t_param *param_tab)
{
	ft_printf("\n%8c -> %s", '|', v->op_tab[list->proc.opc
		- 1].description);
	if (list->proc.opc == 11)
		ft_printf(" %d + %d = %d (with pc and mod %d)",
			helper(v, list->proc, param_tab[1], 0),
			helper(v, list->proc, param_tab[2], 0),
			helper(v, list->proc, param_tab[2], 0)
			+ helper(v, list->proc, param_tab[1], 0),
			(helper(v, list->proc, param_tab[2], 1)
			+ helper(v, list->proc, param_tab[1], 1)) % IDX_MOD
			+ list->proc.pc);
	if (list->proc.opc == 10)
		ft_printf(" %d + %d = %d (with pc and mod %d)",
			helper(v, list->proc, param_tab[0], 0),
			helper(v, list->proc, param_tab[1], 0),
			helper(v, list->proc, param_tab[1], 0)
			+ helper(v, list->proc, param_tab[0], 0),
			(helper(v, list->proc, param_tab[1], 0)
			+ helper(v, list->proc, param_tab[0], 0)) % IDX_MOD
			+ list->proc.pc);
}

void		print_op_exec(t_vm *v, t_plist *list, t_param *param_tab)
{
	if (list->proc.opc == 16)
		return ;
	ft_printf("P%5d | %s ", list->proc.proc_nb,
		v->op_tab[list->proc.opc - 1].name);
	print_params(v, list->proc, param_tab);
	if (list->proc.opc == 9 && list->proc.carry == 1)
		ft_putstr(" OK");
	if (list->proc.opc == 9 && list->proc.carry == 0)
		ft_putstr(" FAILED");
	if (list->proc.opc == 12)
	{
		ft_printf(" (%d)",
			(list->proc.pc + (reverser_16(param_tab[0].val) % IDX_MOD) % MEM_SIZE));
	}
	if (list->proc.opc == 15)
		ft_printf(" (%d)",
				list->proc.pc + reverser_16(param_tab[0].val));
	if ((list->proc.opc > 9 && list->proc.opc <= 11) || list->proc.opc == 14)
		print_op_exec2(v, list, param_tab);
	print_op_exec3(v, list, param_tab);
	ft_putchar('\n');
}
