/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:14:01 by chermist          #+#    #+#             */
/*   Updated: 2020/06/28 20:32:18 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void read_champion(t_parser *parse_struct)
{
	char	*line;
	char	*line_copy;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(parse_struct->fd, &line)) > 0)
	{
		if (ret == -1)
			throw_error("error: Failed to read file");

		ft_putnbr(1);
		line_copy = ft_strdup(line);
		ft_vpush_back(parse_struct->buffer, &line_copy, sizeof(char**));
		ft_putnbr(2);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (parse_struct->buffer->size == 0)
		throw_error("error: Empty champion file");
	if (close(parse_struct->fd) < 0)
		throw_error("error: Failed to close file");
	ft_printf("HERE!!!!");
}

int assemble(const char *filename)
{
	t_parser *parse_struct;

	ft_printf("HERE!!??\n");
	parse_struct = initialize(filename);

	ft_printf("HERE!!!?\n");
	read_champion(parse_struct);
	tokenize(parse_struct);

	int i;
	for (i = 0; i < parse_struct->tokens->size; i++)
	{
		t_token *token;
		token = *(t_token**)(ft_vat(parse_struct->tokens, i));
		ft_printf("line: %d; col: %d; type: %s; content: %s\n", token->line, token->col, token->type, token->content);
	}
	// validate tokens

	// translate

	// free_parse_struct(&parse_struct);
	return (1);
}
