/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:16:21 by chermist          #+#    #+#             */
/*   Updated: 2020/09/17 23:31:13 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parser	*initialize(const char *filename)
{
	t_parser	*parse_struct;

	if (!(parse_struct = ft_memalloc(sizeof(*parse_struct))))
		throw_error("error: Can't allocate memory");
	if ((parse_struct->fd = open(filename, O_RDONLY)) == -1)
		throw_error("error: Can't open champion file");
	parse_struct->line = 1;
	parse_struct->col = 1;
	parse_struct->name = NULL;
	parse_struct->comment = NULL;
	parse_struct->current_byte = 0;
	parse_struct->byte_code = NULL;
	parse_struct->code_len = 0;
	if (!(parse_struct->tokens = ft_vnew(64, sizeof(t_token**))))
		throw_error("error: Can't initialize vector");
	return (parse_struct);
}