/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:53:36 by chermist          #+#    #+#             */
/*   Updated: 2020/07/02 01:12:16 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void save_name(t_parser *parse_struct)
{
	t_token	*t;

	t = *(t_token**)ft_vat(parse_struct->tokens, ++(parse_struct->iter));
	if (t->type == STRING)
	{
		if (!(parse_struct->name = ft_strdup(t->content)))
			throw_error("error: Can't allocate memory");
		if (ft_strlen(parse_struct->name > PROG_NAME_LENGTH))
			throw_error_tokenizing("program name is too long", t->line, t->col);
		parse_struct->iter++;
		parse_struct->token = *(t_token**)ft_vat(parse_struct->tokens, \
														++(parse_struct->iter));
		if (parse_struct->token->type != END_LINE)
			throw_error_tokenizing("missing end line", t->line, t->col);
	}
	else
		throw_error_tokenizing("incorrect token type", t->line, t->col);
}

void save_comment(t_parser *parse_struct)
{
	t_token	*t;

	t = *(t_token**)ft_vat(parse_struct->tokens, ++(parse_struct->iter));
	if (t->type == STRING)
	{
		if (!(parse_struct->comment = ft_strdup(t->content)))
			throw_error("error: Can't allocate memory");
		if (ft_strlen(parse_struct->comment > COMMENT_LENGTH))
			throw_error_tokenizing("comment is too long", t->line, t->col);
		parse_struct->iter++;
		parse_struct->token = *(t_token**)ft_vat(parse_struct->tokens, \
														++(parse_struct->iter));
		if (parse_struct->token->type != END_LINE)
			throw_error_tokenizing("missing end line", t->line, t->col);
	}
	else
		throw_error_tokenizing("incorrect token type", t->line, t->col);
}

void parse_info(t_parser *parse_struct)
{
	t_token	*token;

	token = parse_struct->token;
	if (token->type == COMMAND && !parse_struct->name && \
											(NAME_CMD_STRING, token->content))
		save_name(parse_struct);
	else if (token->type == COMMAND && !parse_struct->comment && \
								ft_strcmp(COMMENT_CMD_STRING, token->content))
		save_comment(parse_struct);
	else 
		throw_error_tokenizing("incorrect token", token->line, token->col);
}

void parse_tokens(t_parser *parse)
{
	parse->iter = 0;
	while (!parse->name && !parse->comment)
	{
		parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
		parse_info(parse);
		parse->iter++;
	}
	while (parse->iter < parse->tokens->size)
	{
		
	}
}