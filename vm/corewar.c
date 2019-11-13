/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:15:17 by adavis            #+#    #+#             */
/*   Updated: 2019/11/13 18:10:08 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	usage(char *name)
{
	ft_printf("Usage: %s <champ1.cor> <...>\n", name);
	return (0);
}

static int	too_many_players(char *name)
{
	ft_printf("Too many arguments. Please provide 1 to %d champs.\n",
																MAX_PLAYERS);
	return (usage(name));
}

int			main(int ac, char **av)
{
	t_corewar		cw;

	if (ac < 2)
		return (usage(av[0]));
	// args_parse(ac, av);
	if (ac > MAX_PLAYERS + 1)
		return (too_many_players(av[0]));
	champs_init(&cw, ac, av);
	arena_init(&cw);
	champs_load(&cw);
	champs_greet(&cw);
	heads_init(&cw);
	heads_print(&cw);
	arena_print(&cw);
}
