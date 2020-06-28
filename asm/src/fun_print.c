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

uint reverseBits(uint num) 
{
	uint  NO_OF_BITS = sizeof(num) * 8; 
	uint reverse_num = 0, i, temp; 
  
	for (i = 0; i < NO_OF_BITS; i++) 
	{ 
		temp = (num & (1 << i)); 
		if(temp) 
			reverse_num |= (1 << ((NO_OF_BITS - 1) - i)); 
	} 
   
	return reverse_num; 
} 


/*
** this function reverses int byte by byte
** thus, big endian -> little endian
*/


uint 	reverse_byte_by_byte_int(uint num)
{
	uint	rev;

	rev = ((num & 0xFF) << 24) | ((num & 0xFF00) << 8) | ((num & 0xFF0000) >> 8) | ((num & 0xFF000000) >> 24);
	return (rev);
}


short 	reverse_byte_by_byte_short(short num)
{
	return ((num << 8) | (num >> 8));	
}

void	print_binary_uint(uint n)
{
	uint mask;

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

void	print_binary_uchar(uchar n)
{
	uchar mask;

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
** free the line if allocated and return whatever is in ret
*/

t_bool	free_line(char **line, t_bool ret)
{
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	return (ret);
}
