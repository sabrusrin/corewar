/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:08:20 by adavis            #+#    #+#             */
/*   Updated: 2019/11/01 19:42:42 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		heads_add(t_head *head)
{
	head = NULL;
	return (0);
}

int		heads_init(t_corewar *cw)
{
	int		i;
	t_head	*heads;
	t_head	*tmp;

	cw->heads = NULL;
	heads = cw->heads;
	i = -1;
	while (++i < cw->champs_cnt)
	{
		tmp = heads;
		heads = malloc(sizeof(t_head));
		heads->id = i;
		heads->carry = 0;
		heads->op_code = -1;
		heads->last_live = -1;
		heads->to_op = -1;
		heads->to_next = -1;
		heads->pos = i * (MEM_SIZE / cw->champs_cnt);
		heads->next = tmp;
		heads->regs = malloc(sizeof(int) * REG_NUMBER);
		heads->regs[0] = -heads->id;
	}
	cw->heads = heads;
	return (0);
}

void	heads_print(t_corewar *cw)
{
	t_head	*heads;

	heads = cw->heads;
	while (heads)
	{
		ft_printf("\nid: %d\n", heads->id);
		ft_printf("carry: %d\n", heads->carry);
		ft_printf("op_code: %d\n", heads->op_code);
		ft_printf("last_live: %d\n", heads->last_live);
		ft_printf("to_op: %d\n", heads->to_op);
		ft_printf("pos: %d\n", heads->pos);
		ft_printf("to_next: %d\n", heads->to_next);
		ft_printf("r1: %d\n", heads->regs[0]);
		heads = heads->next;
	}
}
