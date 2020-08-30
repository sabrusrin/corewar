/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:14:09 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 23:46:48 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdint.h>

int16_t	reverser_16(int16_t a)
{
	return (((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8));
}

int32_t	reverser_32(int32_t a)
{
	int32_t tmp;

	tmp = 0;
	tmp = ((a & 0xFF000000) >> 24) | ((a & 0x00FF) << 24);
	tmp |= ((a & 0x00FF0000) >> 8) | ((a & 0x0000FF00) << 8);
	return (tmp);
}

int		read_ind(t_vm *v, int pos, int size)
{
	int	val;

	val = 0;
	while (size--)
		val |= (unsigned char)v->f.field[get_offset(pos + size)] << (size * 8);
	return (val);
}

void	write_ind(char mem[], int pos, int val, int size)
{
	while (size--)
		mem[get_offset(pos + size)] = (char)(val >> (size * 8));
}

void	write_ind_owner(char mem[], int pos, int val, int size)
{
	while (size--)
		mem[get_offset(pos + size)] = (char)val;
}
