/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:38:39 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/22 22:31:53 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
** this function reverses int byte by byte
** thus, big endian -> little endian
*/

t_uint		reverse_byte_by_byte_int(t_uint num)
{
	t_uint	rev;

	rev = ((num & 0xFF) << 24) | ((num & 0xFF00) << 8) |
	((num & 0xFF0000) >> 8) | ((num & 0xFF000000) >> 24);
	return (rev);
}

/*
** this function reverses bYtes for short type
*/

t_ushort	reverse_byte_by_byte_short(t_ushort num)
{
	return ((num << 8) | (num >> 8));
}

/*
** this function prints uint in binary form
*/

void		print_binary_uint(t_uint n)
{
	t_uint mask;

	mask = 1 << 31;
	while (mask)
	{
		if (n & mask)
			printf("1");
		else
			printf("0");
		mask >>= 1;
	}
	printf("\n");
}

/*
** this function prints uchar in binary form
*/

void		print_binary_uchar(t_uchar n)
{
	t_uchar mask;

	mask = 1 << 7;
	while (mask)
	{
		if (n & mask)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask >>= 1;
	}
	write(1, "\n", 1);
}

/*
** this function prints short in binary form
*/

void		print_binary_short(short n)
{
	unsigned short mask;

	mask = 1 << 15;
	while (mask)
	{
		if (n & mask)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (mask == 256)
			write(1, " ", 1);
		mask >>= 1;
	}
	write(1, "\n", 1);
}
