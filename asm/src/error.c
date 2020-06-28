/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 13:51:19 by chermist          #+#    #+#             */
/*   Updated: 2020/06/28 19:59:34 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void throw_error(char *err)
{
	if (errno == 0)
	{
		ft_putendl_fd(err, 2);
	}
	else
	{
		perror(err);
	}

	exit(1);
}

void throw_error_tokenizing(char *err, int line, int col)
{
	if (err)
	{
		ft_dprintf(2, "lexical error: %s:%d.%d", err, line, col);
		exit(1);
	}
}
