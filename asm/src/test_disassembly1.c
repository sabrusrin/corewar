/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_disassembly1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 23:54:06 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/24 19:12:02 by btrifle          ###   ########.fr       */
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

uchar	arg_byte(uchar opc, uchar arg)
{
	if (arg == 1) //T_REG
		return (1);
	else if (arg == 3) //T_IND
		return (2);
	else if (arg == 2) //T_DIR
	{
		if (g_op_tab[opc - 1].t_dir_short)
			return (2);
		return (4);
	}
	return (0);
}

/*
** before we have parsed the arg_type which is either
** T_REG (1), T_DIR(2), T_IND(3).
** for T_REG we read 1 byte.
** for T_DIR it depends (2 - short or 4 - uint)
** for T_IND we read 2 bytes.
*/

void	read_argument(t_var *v, uchar arg_type, t_bool comma)
{
	if (arg_type == 1) //T_REG, 1 byte
	{
		v->r = read(v->fd, &v->a1, 1);
		v->champ_size--;
		printf("r%hhu", v->a1);
	}
	else if (arg_type == 3) //T_IND, 2 bytes
	{	
		v->r = read(v->fd, &v->a2, 2);
		v->champ_size -= 2;
		printf("r%hu", v->a2);
	}
	else if (arg_type == 2 || arg_type == 4) //T_DIR //можно запутаться с кол-вом байтов и кодом аргумента
	{
		if (g_op_tab[v->opc - 1].t_dir_short) //T_DIR, 2 bytes
		{
			v->r = read(v->fd, &v->a2, 2);
			v->champ_size -= 2;
			v->a2 = reverse_byte_by_byte_short(v->a2);
			printf("%%%hd", v->a2);
		}
		else //T_DIR, 4 bytes
		{
			v->r = read(v->fd, &v->a4, 4);
			v->a4 = reverse_byte_by_byte_int(v->a4);
			v->champ_size -= 4;
			printf("%%%u", v->a4);
		}
	}
	if (comma)
		printf(", ");
	else
		printf(" ");
}

//read first instruction

t_bool	read_instruction(t_var *v)
{
	v->r = read(v->fd, &v->opc, 1);
	v->champ_size--;
	if (v->opc > 0x10)
	{
		ft_putendl_fd("ERROR the instruction is out of range", 2);
		return (false);
	}
	printf("%s ", g_op_tab[v->opc - 1].name);	
	if (g_op_tab[v->opc - 1].op_code != v->opc)
	{
		ft_putendl_fd("ERROR in op.c in order of opcodes\n", 2);
		return (false);
	}
	if (g_op_tab[v->opc - 1].args_number == 2 || g_op_tab[v->opc - 1].args_number == 3) // we read only in case of code size is present
	{
		v->r = read(v->fd, &v->ops_size, 1);
		v->champ_size--;
		read_argument(v, (v->ops_size & 0xc0) >> 6, true); //arg1
		if (g_op_tab[v->opc - 1].args_number == 2)
			read_argument(v, (v->ops_size & 0x30) >> 4, false); //arg2
		else
		{
			read_argument(v, (v->ops_size & 0x30) >> 4, true); //arg2
			read_argument(v, (v->ops_size & 0xc) >> 2, false); //arg3		
		}
	}
	else
	{	
		if (g_op_tab[v->opc - 1].t_dir_short)
			read_argument(v, 2, false); //only arg1, 2 bytes
		else
			read_argument(v, 4, false); //only arg1, 4 bytes		
	}
	printf("\n");	
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

/*
** s_file is t_header exempliar
*/

int main(int argc, char **argv)
{
	t_header s_file;
	
	open_close_s_file(argc, argv, &s_file);
	return(0);
}