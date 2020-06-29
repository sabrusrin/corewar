/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_read2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:26:45 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/29 14:26:48 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
** the provided files should have .cor extension
** that we check here
*/

t_bool	check_files_names(int argc, char **argv)
{
	char	*point;
	int		i;

	i = 1;
	while (i < argc)
	{
		point = ft_strrchr(argv[i], '.');
		if (point == NULL)
		{
			ft_putstr_fd("ERROR format not supported for ", 2);
			ft_putendl_fd(argv[i], 2);
			return (false);
		}
		if (ft_strncmp(point, ".cor", 4) != 0)
		{
			ft_putstr_fd("ERROR please provide .cor file", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

/*
** this function determines number of bytes for argument.
** we need opcode and argument itself.
** if the arguments passed is 0, return 0
** for T_REG return 1 byte
** for T_IND return 2 bytes
** for T_DIR return 2 or 4 bytes depending on opc (opcode)
*/

t_uchar	arg_byte(t_uchar opc, t_uchar arg)
{
	if (arg == 1)
		return (1);
	else if (arg == 3)
		return (2);
	else if (arg == 2)
	{
		if (g_op_tab[opc - 1].t_dir_short)
			return (2);
		return (4);
	}
	return (0);
}

/*
** this function is used below in read_argument
** for reading 2 or 4 bytes (for T_DIR)
*/

void	read_argument_2_4_bytes(t_var *v)
{
	if (g_op_tab[v->opc - 1].t_dir_short)
	{
		v->r = read(v->fd, &v->a2, 2);
		v->champ_size -= 2;
		v->a2 = reverse_byte_by_byte_short(v->a2);
		ft_printf("%%%hd", v->a2);
	}
	else
	{
		v->r = read(v->fd, &v->a4, 4);
		v->a4 = reverse_byte_by_byte_int(v->a4);
		v->champ_size -= 4;
		ft_printf("%%%u", v->a4);
	}
}

/*
** before we have parsed the arg_type which is either
** T_REG (1), T_DIR(2), T_IND(3).
** for T_REG we read 1 byte.
** for T_DIR it depends (2 - short or 4 - uint)
** for T_IND we read 2 bytes.
** when arg_type is 4 this means 4 bytes
*/

void	read_argument(t_var *v, t_uchar arg_type, t_bool comma)
{
	if (arg_type == 1)
	{
		v->r = read(v->fd, &v->a1, 1);
		v->champ_size--;
		ft_printf("r%hhu", v->a1);
	}
	else if (arg_type == 3)
	{
		v->r = read(v->fd, &v->a2, 2);
		v->champ_size -= 2;
		ft_printf("%hd", reverse_byte_by_byte_short(v->a2));
	}
	else if (arg_type == 2 || arg_type == 4)
		read_argument_2_4_bytes(v);
	if (comma)
		ft_printf(", ");
	else
		ft_printf(" ");
}
