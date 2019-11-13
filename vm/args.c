/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:23:47 by adavis            #+#    #+#             */
/*   Updated: 2019/11/13 14:50:33 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	invalid_n(char *name)
{
	ft_printf("Invalid arguments after -n flag.\n");
	ft_printf("Usage: %s -n <champ_position> <champ_file>\n", name);
	exit(-1);
}

int			args_parse(int ac, char **av)
{
	int		i;
	char	**champs;

	champs = (char **)ft_strnew(MAX_PLAYERS);
	i = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-n"))
		{
			if (i + 2 >= ac || av[i + 1][1] != 0 || av[i + 1][0] < '1' ||
											av[i + 1][0] > '0' + MAX_PLAYERS)
				invalid_n(av[0]);
			
		}
	}
	return (0);
}
