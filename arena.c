/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:11:39 by adavis            #+#    #+#             */
/*   Updated: 2019/10/31 17:18:21 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		arena_init(t_corewar *cw) {
	t_memcell	*arena;
	int			i;

	if (!(arena = malloc(sizeof(t_memcell) * MEM_SIZE)))
		return (0);
	i = -1;
	while (++i < MEM_SIZE) {
		arena[i].value = 0;
		arena[i].player_id = -1;
	}
	cw->arena = arena;
	return (1);
}

void	arena_print(t_corewar *cw)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE) {
		if (cw->arena[i].player_id >= 0)
			ft_printf("\e[%dm", 31 + cw->arena[i].player_id);
		ft_printf("%.2x\e[0m %s", cw->arena[i].value, (i + 1) % 64 ? "" : "\n");
	}
}
