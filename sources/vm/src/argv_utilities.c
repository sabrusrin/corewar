/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:48:42 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 23:42:25 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int	verbose(int argc, char **argv, t_parse_argv *av, t_vm *v)
{
	if (av->is_verbose)
		return (ft_usage());
	av->is_verbose = 1;
	if ((v->verbose = ft_number(argc, argv, av)) < 0)
		return (ft_usage());
	return (0);
}

int	dump(int argc, char **argv, t_parse_argv *av, t_vm *v)
{
	if (av->is_dump)
		return (ft_usage());
	av->is_dump = 1;
	v->dirty = 0;
	if ((v->dump_cycle = ft_number(argc, argv, av)) < 0)
		return (ft_usage());
	return (0);
}

int	dirty(int argc, char **argv, t_parse_argv *av, t_vm *v)
{
	if (av->is_dump)
		return (ft_usage());
	av->is_dump = 1;
	v->dirty = 1;
	if ((v->dump_cycle = ft_number(argc, argv, av)) < 0)
		return (ft_usage());
	return (0);
}

int	num_champ(int argc, char **argv, t_parse_argv *av, t_vm *v)
{
	(void)v;
	av->nb_champ = ft_number(argc, argv, av);
	if (av->bool)
		return (ft_usage());
	av->count_nb++;
	av->is_nb = 1;
	return (0);
}

int	init_visu(int argc, char **argv, t_parse_argv *av, t_vm *v)
{
	(void)argc;
	(void)argv;
	if (av->is_visu || av->is_verbose || av->is_dump)
		return (ft_usage());
	av->is_visu = 1;
	v->visu = 1;
	av->is_verbose = 1;
	v->verbose = 0;
	av->is_dump = 1;
	v->dump_cycle = -1;
	return (0);
}
