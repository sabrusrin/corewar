/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:14:01 by chermist          #+#    #+#             */
/*   Updated: 2020/07/01 15:34:43 by chermist         ###   ########.fr       */
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

		line_copy = ft_strdup(line);
		ft_vpush_back(parse_struct->buffer, &line_copy, sizeof(char**));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (parse_struct->buffer->size == 0)
		throw_error("error: Empty champion file");
	if (close(parse_struct->fd) < 0)
		throw_error("error: Failed to close file");
}

int assemble(const char *filename)
{
	t_parser *parse_struct;

	parse_struct = initialize(filename);

	read_champion(parse_struct);
	tokenize(parse_struct);

// ---------------------------------------------------------------------------
// tokenize test
	int i;
	for (i = 0; i < parse_struct->tokens->size; i++)
	{
		t_token *token;
		token = *(t_token**)(ft_vat(parse_struct->tokens, i));
		ft_printf("line: %d; col: %d; type: %s; content: %s\n", token->line, token->col, token->type, token->content);
	}
// tokenize test
// ---------------------------------------------------------------------------

	// validate tokens

	// translate

	// free_parse_struct(&parse_struct);
	return (1);
}
