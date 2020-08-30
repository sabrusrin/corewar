/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:33:29 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 23:55:07 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	intro(t_vm *v)
{
	int		i;

	i = -1;
	ft_putstr("Introducing contestants...\n");
	while (++i < v->nb_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			ft_abs(v->players[i].nb_champ), v->players[i].head.prog_size,
			v->players[i].head.name, v->players[i].head.comment);
	}
}
