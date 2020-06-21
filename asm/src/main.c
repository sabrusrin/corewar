/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:01:25 by chermist          #+#    #+#             */
/*   Updated: 2020/06/21 21:47:30 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **av)
{
	if (ac == 2 && check_filename(av[1], ".s"))
	{
		if (assemble(av[1]))
			ft_printf("champion successfully assembled");
		else
		{
			ft_putendl_fd("failed to assemble champion", 2);
			exit (1);
		}
	}
	else if (ac == 2 && check_filename(av[1], ".cor"))
	{
		ft_printf("disassembler");
		// disassemble(av[1]);
	}
	else
		ft_printf("usage:\n\t- ./asm *.s\n\t- ./asm *.cor");
	
	return (0);
}
