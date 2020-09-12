/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:14:01 by chermist          #+#    #+#             */
/*   Updated: 2020/09/12 16:04:08 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// void read_champion(t_parser *parse_struct)
// {
// 	char	*line;
// 	char	*line_copy;
// 	int		ret;

// 	line = NULL;
// 	while ((ret = get_next_line(parse_struct->fd, &line)) > 0)
// 	{
// 		if (ret == -1)
// 			throw_error("error: Failed to read file");

// 		line_copy = ft_strdup(line);
// 		ft_vpush_back(parse_struct->buffer, &line_copy, sizeof(char**));
// 		ft_strdel(&line);
// 	}
// 	ft_strdel(&line);
// 	if (parse_struct->buffer->size == 0)
// 		throw_error("error: Empty champion file");
// 	if (close(parse_struct->fd) < 0)
// 		throw_error("error: Failed to close file");
// }

int assemble(const char *filename)
{
	t_parser *parse_struct;
	t_token  *test;
	int      test_i;

	parse_struct = initialize(filename);

	// read_champion(parse_struct);
	tokenize(parse_struct);

	//tokenizer out
	// for (test_i = 0; test_i < parse_struct->tokens->size; test_i++) {
	// 	test = *(t_token**)ft_vat(parse_struct->tokens, test_i);
	// 	ft_printf("%d__%d\t%d\t%s\n", test->line, test->col, test->type, test->content);
	// }

	// validate tokens
	parse_tokens(parse_struct);

	// translate

	// free_parse_struct(&parse_struct);
	return (1);
}
