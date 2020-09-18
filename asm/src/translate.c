/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:54 by chermist          #+#    #+#             */
/*   Updated: 2020/09/19 00:50:28 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void put_magic(t_parser *parse, int *pos)
{
	parse->byte_code[(*pos)++] = (char)0x00;
	parse->byte_code[(*pos)++] = (char)0xea;
	parse->byte_code[(*pos)++] = (char)0x83;
	parse->byte_code[(*pos)++] = (char)0xf3;
}

void put_name(t_parser *parse, int *pos)
{
	int i;
	int c;

	i = 0;
	c = *pos;
	while (parse->name[i])
		parse->byte_code[(*pos)++] = parse->name[i++];
	*pos = c + PROG_NAME_LENGTH + 4;
}

void put_comment(t_parser *parse, int *pos)
{
	int i;
	int c;

	i = 0;
	c = *pos;
	while (parse->comment[i])
		parse->byte_code[(*pos)++] = parse->comment[i++];
	*pos = c + PROG_NAME_LENGTH + 4;
}

void put_code_size(t_parser *parse, int *pos)
{
	unsigned char *byte;
	int i;

	byte = ((unsigned char*)&(parse->current_byte)) + 3;
	i = 0;
	while (i++ < 4)
		parse->byte_code[(*pos)++] = *byte--;
}

void put_arg(t_parser *parse, int *pos, t_token *arg)
{
	
}

void put_commands(t_parser *parse, int *pos)
{
	t_token	*arg;
	int	arg_i;

	parse->iter = 0;
	parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
	while (parse->iter < parse->tokens->size)
	{
		if (parse->token->type == INSTRUCTION)
		{
			parse->byte_code[(*pos)++] = parse->token->op_code;
			if (parse->token->args_code)
				parse->byte_code[(*pos)++] = parse->token->args_code;
			arg_i = 0;
			while (arg_i < parse->token->args->size)
			{
				arg = *(t_token**)ft_vat(parse->token->args, arg_i);
				put_arg(parse, pos, arg);
				arg_i++;
			}
		}
		parse->token = (*(t_token**)ft_vat(parse->tokens, \
													++(parse->iter)));
	}
}

void translate(t_parser *parse)
{
	int	len;
	int i;
	int current_pos;

	i = 0;
	current_pos = 0;
	len = parse->current_byte + PROG_NAME_LENGTH + COMMENT_LENGTH + 17;
	ft_putnbr(len);
	if (!(parse->byte_code = malloc(len)))
		throw_error("error: Can't allocate memory");
	while (i < len)
		parse->byte_code[i++] = 0;
	parse->code_len = len;

	put_magic(parse, &current_pos);
	put_name(parse, &current_pos);
	put_comment(parse, &current_pos);
	put_code_size(parse, &current_pos);
	put_commands(parse, &current_pos);
}