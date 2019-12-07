/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:47:36 by adavis            #+#    #+#             */
/*   Updated: 2019/12/07 15:03:21 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		champs_greet(t_corewar *cw)
{
	int		i;

	ft_printf("\e[7m # | %-32s| %-64s| %-4s  \e[0m\n",
													"Name", "Comment", "Size");
	i = -1;
	while (++i < cw->champs_cnt)
	{
		ft_printf(" %d | ", i + 1);
		ft_printf("%-32s| ", cw->champs[i].name);
		ft_printf("%-64s| ", cw->champs[i].comment);
		ft_printf("%d\n", cw->champs[i].size);
	}
	return (0);
}

// TODO: Выстроить список в соответствии с флагом -n
int		champs_init(t_corewar *cw, int ac, char **av)
{
	int		i;

	cw->champs_cnt = ac - 1;
	cw->champs = (t_champ *)malloc(sizeof(t_champ) * cw->champs_cnt);
	i = -1;
	while (++i + 1 < ac)
	{
		if ((cw->champs[i].fd = open(av[i + 1], O_RDONLY)) == -1)
			exit_open(av[i + 1]);
		if (hex_get_nbr(cw->champs[i].fd, 4) != COREWAR_EXEC_MAGIC)
			exit_header();
		cw->champs[i].name = hex_get_string(cw->champs[i].fd, PROG_NAME_LENGTH);
		if (!hex_check_null(cw->champs[i].fd))
			exit_null_block();
		cw->champs[i].size = hex_get_nbr(cw->champs[i].fd, 4);
		cw->champs[i].comment = hex_get_string(cw->champs[i].fd,
																COMMENT_LENGTH);
		if (!hex_check_null(cw->champs[i].fd))
			exit_null_block();
	}
	cw->champs_cnt = i;
	return (0);
}

int		champs_load(t_corewar *cw)
{
	int				i;
	int				j;
	unsigned char	buf;

	i = -1;
	while (++i < cw->champs_cnt)
	{
		j = -1;
		while (++j < cw->champs[i].size)
		{
			read(cw->champs[i].fd, &buf, 1);
			memcell_set(cw, i * (MEM_SIZE / cw->champs_cnt) + j, buf, i);
		}
	}
	return (0);
}
