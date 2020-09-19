/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:01:25 by chermist          #+#    #+#             */
/*   Updated: 2020/09/19 10:52:53 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **av)
{
	if (ac == 2 && check_filename(av[1], ".s"))
		assemble(av[1]);
	else if (ac == 2 && check_filename(av[1], ".cor"))
	{
		ft_printf("disassembler");
		// disassemble(av[1]);
	}
	else
		ft_printf("usage:\n\t- ./asm *.s\n\t- ./asm *.cor");
	
	return (0);
}
