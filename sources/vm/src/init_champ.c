/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:39:28 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 23:52:03 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "corewar.h"

static int	ft_check_header(char *argv, t_champ *player)
{
	if ((player->head.magic = reverser_32(player->head.magic))
		!= COREWAR_EXEC_MAGIC)
	{
		ft_putendl("Wrong magic value");
		return (-1);
	}
	if ((player->head.prog_size = reverser_32(player->head.prog_size)) > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large a code (%d bytes > %d bytes)\n",
			argv, player->head.prog_size, CHAMP_MAX_SIZE);
		return (-1);
	}
	return (0);
}

static int	ft_read_header(char *argv, int fd, t_champ *player)
{
	int	size;

	if ((size = read(fd, &player->head, sizeof(t_header))) < 0)
	{
		ft_putendl("Can't read header");
		return (-1);
	}
	if (!size)
	{
		ft_printf("Error: File %s is too small to be a champion\n", argv);
		return (-1);
	}
	else if (size != sizeof(t_header))
	{
		ft_putendl("Wrong header size");
		return (-1);
	}
	if (ft_check_header(argv, player))
		return (-1);
	return (0);
}

static int	ft_read(char **argv, t_parse_argv *av, t_champ *player)
{
	int		fd;
	int		size;
	int		ret;

	ret = 0;
	if ((fd = open(argv[av->i], O_RDONLY)) == -1)
	{
		ft_putendl("Can't open file");
		ret = -1;
	}
	if (!ret && ft_read_header(argv[av->i], fd, player))
		ret = -1;
	if (!ret)
		size = read(fd, &player->prog, 2147483647);
	if (!ret && (!player->head.prog_size
		|| (unsigned int)size != player->head.prog_size))
	{
		ft_printf("Error: File %s has a code size that differ from what its %s",
			argv[av->i], "header says\n");
		ret = -1;
	}
	if (close(fd))
		return (-1);
	return (ret);
}

int			ft_init_champ(int argc, char **argv, t_parse_argv *av, t_vm *v)
{
	int	i;
	int	j;

	(void)argc;
	i = 0;
	while (v->players[i].head.magic == COREWAR_EXEC_MAGIC)
		i++;
	if (ft_read(argv, av, &v->players[i]))
		return (-1);
	else
	{
		v->players[i].nb_champ = av->is_nb ? av->nb_champ
		: i - av->count_nb + 1;
		av->is_nb = 0;
		j = -1;
		while (++j < i)
			if (v->players[j].nb_champ == v->players[i].nb_champ)
				return (ft_usage());
	}
	return (0);
}
