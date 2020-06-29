/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_read1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:28:44 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/29 14:28:56 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_bool	read_size(t_var *v)
{
	v->r = read(v->fd, &v->opc, 1);
	v->champ_size--;
	if (v->opc > 0x10)
	{
		ft_putendl_fd("ERROR the instruction is out of range", 2);
		return (false);
	}
	ft_printf("%s ", g_op_tab[v->opc - 1].name);
	if (g_op_tab[v->opc - 1].op_code != v->opc)
	{
		ft_putendl_fd("ERROR in op.c in order of opcodes\n", 2);
		return (false);
	}
	return (true);
}

t_bool	read_instruction(t_var *v)
{
	if (read_size(v) == false)
		return (false);
	if (g_op_tab[v->opc - 1].args_number == 2 ||
	g_op_tab[v->opc - 1].args_number == 3)
	{
		v->r = read(v->fd, &v->ops_size, 1);
		v->champ_size--;
		read_argument(v, (v->ops_size & 0xc0) >> 6, true);
		if (g_op_tab[v->opc - 1].args_number == 2)
			read_argument(v, (v->ops_size & 0x30) >> 4, false);
		else
		{
			read_argument(v, (v->ops_size & 0x30) >> 4, true);
			read_argument(v, (v->ops_size & 0xc) >> 2, false);
		}
	}
	else
	{
		if (g_op_tab[v->opc - 1].t_dir_short)
			read_argument(v, 2, false);
		else
			read_argument(v, 4, false);
	}
	ft_printf("\n");
	return (true);
}

/*
** r is number of bytes which are read from *.s file
*/

t_bool	read_s_file(t_var *v, t_header *f)
{
	if (read_magic_header(v) == false)
		return (false);
	read_champ_name(v, f);
	if (read_null(v) == false)
		return (false);
	if (read_champ_size(v) == false)
		return (false);
	read_champ_comment(v, f);
	if (read_null(v) == false)
		return (false);
	while (v->champ_size > 0)
	{
		if (read_instruction(v) == false)
			return (false);
	}
	return (true);
}

/*
** we open *.cor file
*/

t_bool	open_close_s_file(int argc, char **argv, t_header *f)
{
	int		i;
	t_var	v;

	i = 1;
	if (check_files_names(argc, argv) == false)
		return (false);
	while (i < argc)
	{
		v.fd = open(argv[i], O_RDONLY, 0);
		if (v.fd < 0)
		{
			ft_putendl_fd("ERROR couldn't open file", 2);
			return (false);
		}
		read_s_file(&v, f);
		close(v.fd);
		i++;
	}
	return (true);
}
