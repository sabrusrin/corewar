/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:34:11 by adavis            #+#    #+#             */
/*   Updated: 2019/11/01 19:40:28 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	exit_null_block(void)
{
	ft_printf("NULL block error\n");
	exit(-1);
}

void	exit_header(void)
{
	ft_printf("Header error\n");
	exit(-1);
}

void	exit_open(char *file)
{
	ft_printf("Couldn't open %s\n", file);
	exit(-1);
}
