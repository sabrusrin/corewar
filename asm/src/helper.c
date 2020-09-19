/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:11:22 by chermist          #+#    #+#             */
/*   Updated: 2020/07/01 15:30:04 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		string_len(char **carriage, char delim)
{
	int	i;

	i = 0;
	while ((*carriage)[i] && (*carriage)[i] != delim)
		i++;
	if (i == 0)
		return (0);
	return (i);
}

void	comment_skip(t_parser *parse_struct, char **carriage)
{
	while (**carriage)
	{
		(*carriage)++;
		parse_struct->col++;
	}
}
