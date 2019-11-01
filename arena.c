/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:11:39 by adavis            #+#    #+#             */
/*   Updated: 2019/11/01 19:40:16 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		arena_init(t_corewar *cw)
{
	int			i;

	if (!(cw->arena = malloc(sizeof(t_memcell) * MEM_SIZE)))
		return (0);
	i = -1;
	while (++i < MEM_SIZE)
		memcell_set(cw, i, 0, -1);
	return (1);
}

void	arena_print(t_corewar *cw)
{
	int		i;
	t_head	*heads;

	i = -1;
	while (++i < MEM_SIZE)
	{
		heads = cw->heads;
		while (heads)
		{
			if (heads->pos == i)
				ft_printf("\e[7m");
			heads = heads->next;
		}
		if (cw->arena[i].champ_id >= 0)
			ft_printf("\e[%dm", 31 + cw->arena[i].champ_id);
		ft_printf("%.2x\e[0m %s", cw->arena[i].value, (i + 1) % 64 ? "" : "\n");
		ft_printf("\e[27m");
	}
}
