/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:53:36 by chermist          #+#    #+#             */
/*   Updated: 2020/09/12 16:52:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token *take_next_token(t_parser *parse_struct)
{
	if (parse_struct->iter + 1 < parse_struct->tokens->size)
		retrurn (*(t_token**)ft_vat(parse_struct->tokens, \
													++(parse_struct->iter)));
	else
		throw_error_tokenizing("incomplete code", parse_struct->token->line, \
												parse_struct->token->line);
}

void save_name(t_parser *parse_struct)
{
	t_token	*t;

	t = take_next_token(parse_struct);
	if (t->type == STRING)
	{
		if (!(parse_struct->name = ft_strdup(t->content)))
			throw_error("error: Can't allocate memory");
		if (ft_strlen(parse_struct->name) > PROG_NAME_LENGTH)
			throw_error_tokenizing("program name is too long", t->line, t->col);
		parse_struct->token = take_next_token(parse_struct);
		if (parse_struct->token->type != END_LINE)
			throw_error_tokenizing("missing end line", t->line, t->col);
	}
	else
		throw_error_tokenizing("incorrect token type", t->line, t->col);
}

void save_comment(t_parser *parse_struct)
{
	t_token	*t;

	t = take_next_token(parse_struct);
	if (t->type == STRING)
	{
		if (!(parse_struct->comment = ft_strdup(t->content)))
			throw_error("error: Can't allocate memory");
		if (ft_strlen(parse_struct->comment) > COMMENT_LENGTH)
			throw_error_tokenizing("comment is too long", t->line, t->col);
		parse_struct->token = take_next_token(parse_struct);
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
								!ft_strcmp(NAME_CMD_STRING, token->content))
		save_name(parse_struct);
	else if (token->type == COMMAND && !parse_struct->comment && \
								!ft_strcmp(COMMENT_CMD_STRING, token->content))
		save_comment(parse_struct);
	else 
		throw_error_tokenizing("incorrect token", token->line, token->col);
}

void parse_label(t_parser *parse)
{
	t_token	*token;

	token = take_next_token(parse);
	if (token->type != INSTRUCTION && \
		token->type != END_LINE && \
		token->type != END)
		throw_error_tokenizing("incorrect token", token->line, token->col);
}

void parse_instruction(t_parser *parse)
{

}

void parse_tokens(t_parser *parse)
{
	parse->iter = 0;
	while (parse->iter < parse->tokens->size) {
		parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
		if (parse->token->type == END_LINE)
			continue ;
		if (parse->token->type == COMMAND)
			parse_info(parse);
		else
			throw_error_tokenizing("missing name or comment", 0, 0);
		if (parse->name && parse->comment)
			break ;
		parse->iter++;
	}
	// while (parse->iter < parse->tokens->size && \
	// 										(!parse->name || !parse->comment))
	// {
	// 	parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
	// 	parse_info(parse);
	// 	parse->iter++;
	// }
	(!parse->name || !parse->comment || parse->iter >= parse->tokens->size) ? \
		throw_error_tokenizing("missing name or comment", 0, 0) : 0;
	while (parse->iter < parse->tokens->size)
	{
		// endline shouldn't trigger exit from program or should?
		parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
		if (parse->token->type == LABEL)
			parse_label(parse);
		else if (parse->token->type == INSTRUCTION)
			parse_instruction(parse);
		else
			throw_error_tokenizing("incorrect token", parse->token->line, \
															parse->token->col);
		if (parse->token->type == END_LINE)
			parse->iter++;
		else
			throw_error_tokenizing("missing end line", parse->token->line, \
															parse->token->col);
	}
}