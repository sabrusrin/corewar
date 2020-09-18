/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:53:36 by chermist          #+#    #+#             */
/*   Updated: 2020/09/19 00:43:01 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token *take_next_token(t_parser *parse_struct)
{
	if (parse_struct->iter + 1 < parse_struct->tokens->size)
		return (*(t_token**)ft_vat(parse_struct->tokens, \
													++(parse_struct->iter)));
	else
		throw_error_tokenizing("incomplete code", parse_struct->token->line, \
												parse_struct->token->col);
	return (NULL);
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
		// parse_struct->token = take_next_token(parse_struct);
		// if (parse_struct->token->type != END_LINE)
			// throw_error_tokenizing("missing end line", t->line, t->col);
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
		// parse_struct->token = take_next_token(parse_struct);
		// if (parse_struct->token->type != END_LINE)
			// throw_error_tokenizing("missing end line", t->line, t->col);
	}
	else
		throw_error_tokenizing("incorrect token type", t->line, t->col);
}

void parse_info(t_parser *parse_struct)
{
	t_token	*token;

	token = parse_struct->token;
	if (!parse_struct->name && !ft_strcmp(NAME_CMD_STRING, token->content))
		save_name(parse_struct);
	else if (!parse_struct->comment && \
								!ft_strcmp(COMMENT_CMD_STRING, token->content))
		save_comment(parse_struct);
	else 
		throw_error_tokenizing("incorrect token", token->line, token->col);
}

void parse_label(t_parser *parse)
{
	parse->token = take_next_token(parse);
	// ft_printf("{%s__%d}\n", parse->token->content, parse->token->type);
	if (parse->token->type != INSTRUCTION && parse->token->type != END)
		throw_error_tokenizing("incorrect token", parse->token->line, \
															parse->token->col);
}

void parse_tokens(t_parser *parse)
{
	parse->iter = 0;
	while (parse->iter < parse->tokens->size) {
		parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
		if (parse->token->type == COMMAND)
			parse_info(parse);
		else
			throw_error_tokenizing("missing name or comment", 0, 0);
		if (parse->name && parse->comment)
			break ;
		(parse->iter)++;
	}
	(parse->iter)++;
	(!parse->name || !parse->comment || parse->iter >= parse->tokens->size) ? \
		throw_error_tokenizing("missing name or comment", 0, 0) : 0;
	while (parse->iter < parse->tokens->size)
	{
		parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
		// ft_printf("%s__%d\n",parse->token->content, parse->token->type);
		if (parse->token->type == LABEL)
		{
			parse_label(parse);
			continue ;
		}
		else if (parse->token->type == INSTRUCTION)
			parse_instruction(parse);
		else if (parse->token->type != END)
		{

	// ft_putstr("here\n");
			throw_error_tokenizing("incorrect token", parse->token->line, \
															parse->token->col);
		}
		(parse->iter)++;
	}
}