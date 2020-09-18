/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:14:01 by chermist          #+#    #+#             */
/*   Updated: 2020/09/18 00:40:29 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int assemble(const char *filename)
{
	t_parser	*parse_struct;
	// t_token		*test;
	// int			test_i;

	parse_struct = initialize(filename);

	// read_champion(parse_struct);
	tokenize(parse_struct);

	// tokenizer out
	// for (test_i = 0; test_i < parse_struct->tokens->size; test_i++) {
	// 	test = *(t_token**)ft_vat(parse_struct->tokens, test_i);
	// 	ft_printf("_%d__%d\t%d\t%s_\n", test->line, test->col, test->type, test->content);
	// }

	// validate tokens
	parse_tokens(parse_struct);
	parse_arguments(parse_struct);

	ft_printf("KKKKKKKK\n");
	calc_size(parse_struct);
	ft_printf("KKKKKKKK\n");

	// translate
	translate(parse_struct);

	// free_parse_struct(&parse_struct);
	return (1);
}
