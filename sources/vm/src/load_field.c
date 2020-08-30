/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:07:04 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/09 19:03:18 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static void	load_champions(t_vm *v)
{
	int		i;

	i = -1;
	while (++i < v->nb_players)
	{
		ft_memcpy(v->f.field + (i * MEM_SIZE / v->nb_players),
				v->players[i].prog, v->players[i].head.prog_size);
		ft_memset(v->f.owner + (i * MEM_SIZE / v->nb_players), i,
				v->players[i].head.prog_size);
	}
}

int			load_field(t_vm *v)
{
	ft_memset(v->f.field, 0, MEM_SIZE);
	ft_memset(v->f.owner, 4, MEM_SIZE);
	load_champions(v);
	return (1);
}
