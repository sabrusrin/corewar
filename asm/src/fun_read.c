/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:38:52 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/24 18:53:24 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
** read 4 bytes which represent magic number
*/

t_bool	read_magic_header(t_var *v)
{
	unsigned int	mag;
	
	v->r = read(v->fd, &mag, 4);
	if (mag != 0xf383ea00 || v->r < 1)
	{
		ft_putstr_fd("ERROR: not binary file provided. ", 2);
		ft_putendl_fd("Magic header is not suitable", 2);
		return (false);
	}
	return (true);
}

/*
** read 128 bytes which is the champ name
*/

void	read_champ_name(t_var *v, t_header *f)
{
	int i;
	
	v->r = read(v->fd, f->prog_name, PROG_NAME_LENGTH);
	f->prog_name[PROG_NAME_LENGTH] = '\0';
	i = 0;
	while (i < 128)
	{
		if (!ft_isprint(f->prog_name[i]))
		{
			f->prog_name[i] = '\0';
			break ;
		}
		i++;
	}
	ft_printf("\033[0;31m.name: %s\033[0m\n", f->prog_name);
}

/*
** read 4 bytes which must be NULL
** used after reading champ's name and comment
*/

t_bool	read_null(t_var *v)
{
	v->r = read(v->fd, &v->tmp, 4);
	if (v->r < 1 || v->tmp != 0)
	{
		ft_putendl_fd("ERROR no zeros after champ name", 2);
		return (false);
	}
	return (true);
}

/*
**	read champ size and assure that it's no more than 4096/6 ~ 682 
*/

t_bool	read_champ_size(t_var *v)
{
	v->r = read(v->fd, &v->champ_size, 4);
	v->champ_size = reverse_byte_by_byte_int(v->champ_size);
	// printf("size = %u\n", v->champ_size);
	if (v->champ_size >= CHAMP_MAX_SIZE)
	{
		ft_putendl_fd("ERROR: instructions for champion exceed 682 bytes.", 2);
		return (false);
	}
	return (true);
}

/*
** read 2048 bytes as champ comment
*/

void	read_champ_comment(t_var *v, t_header *f)
{
	int i;
	
	v->r = read(v->fd, f->comment, COMMENT_LENGTH);
	f->comment[COMMENT_LENGTH] = '\0';
	i = 0;
	while (i < 2048)
	{
		if (!ft_isprint(f->comment[i]))
		{
			f->comment[i] = '\0';
			break ;
		}
		i++;
	}
	ft_printf("\033[0;31m.comment: %s\033[0m\n", f->comment);
}
