/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:23:16 by chermist          #+#    #+#             */
/*   Updated: 2020/09/18 00:48:27 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	live_zjmp_fork_lfork(t_parser *parse)
{
	t_token *arg;

	if (parse->token->args->size != 1)
		throw_error_tokenizing("invalid ammount of arguments, 1 needed",
										parse->token->line, parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 0);
	if (arg->type != DIRECT && arg->type != DIRECT_LABEL)
		throw_error_tokenizing("invalid argument 2", parse->token->line, \
											parse->token->col);
}

void	ld_lld(t_parser *parse)
{
	t_token *arg;

	if (parse->token->args->size != 2)
		throw_error_tokenizing("invalid ammount of arguments, 2 needed", \
										parse->token->line, parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 0);
	if (arg->type != DIRECT && arg->type != DIRECT_LABEL \
		&& arg->type != INDIRECT && arg->type != INDIRECT_LABEL)
		throw_error_tokenizing("invalid argument 1", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 1);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid arguments 2", parse->token->line, \
											parse->token->col);
}

void	st(t_parser *parse)
{
	t_token *arg;

	if (parse->token->args->size != 2)
		throw_error_tokenizing("invalid ammount of arguments, 2 needed", \
										parse->token->line, parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 0);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid argument 1", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 1);
	if (arg->type != REGISTER && arg->type != INDIRECT && \
												arg->type != INDIRECT_LABEL)
		throw_error_tokenizing("invalid argument 2", parse->token->line, \
											parse->token->col);
}

void	add_sub(t_parser *parse)
{
	t_token *arg;

	if (parse->token->args->size != 3)
		throw_error_tokenizing("invalid ammount of arguments, 3 needed", \
										parse->token->line, parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 0);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid argument 1", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 1);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid argument 2", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 2);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid argument 3", parse->token->line, \
											parse->token->col);
}

void	and_or_xor(t_parser *parse)
{
	t_token *arg;

	if (parse->token->args->size != 3)
		throw_error_tokenizing("invalid ammount of arguments, 3 needed", \
										parse->token->line, parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 0);
	if (arg->type != REGISTER && arg->type != INDIRECT && arg->type != DIRECT \
		&& arg->type != INDIRECT_LABEL && arg->type != DIRECT_LABEL)
		throw_error_tokenizing("invalid argument 1", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 1);
	if (arg->type != REGISTER && arg->type != INDIRECT && arg->type != DIRECT \
		&& arg->type != INDIRECT_LABEL && arg->type != DIRECT_LABEL)
		throw_error_tokenizing("invalid argument 2", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 2);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid argument 3", parse->token->line, \
											parse->token->col);
}

void	ldi_lldi(t_parser *parse)
{
	t_token *arg;

	if (parse->token->args->size != 3)
		throw_error_tokenizing("invalid ammount of arguments, 3 needed", \
										parse->token->line, parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 0);
	if (arg->type != REGISTER && arg->type != INDIRECT && arg->type != DIRECT \
		&& arg->type != INDIRECT_LABEL && arg->type != DIRECT_LABEL)
		throw_error_tokenizing("invalid argument 1", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 1);
	if (arg->type != REGISTER && arg->type != DIRECT && \
													arg->type != DIRECT_LABEL)
		throw_error_tokenizing("invalid argument 2", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 2);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid argument 3", parse->token->line, \
											parse->token->col);
}

void	sti(t_parser *parse)
{
	t_token *arg;

	if (parse->token->args->size != 3)
		throw_error_tokenizing("invalid ammount of arguments, 3 needed", \
										parse->token->line, parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 0);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid argument 1", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 1);
	if (arg->type != REGISTER && arg->type != INDIRECT && arg->type != DIRECT \
		&& arg->type != INDIRECT_LABEL && arg->type != DIRECT_LABEL)
		throw_error_tokenizing("invalid argument 2", parse->token->line, \
											parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 2);
	if (arg->type != REGISTER && arg->type != DIRECT && \
													arg->type != DIRECT_LABEL)
		throw_error_tokenizing("invalid argument 3", parse->token->line, \
											parse->token->col);
}

void	aff(t_parser *parse)
{
	t_token *arg;

	if (parse->token->args->size != 1)
		throw_error_tokenizing("invalid ammount of arguments, 1 needed",
										parse->token->line, parse->token->col);
	arg = *(t_token**)ft_vat(parse->token->args, 0);
	if (arg->type != REGISTER)
		throw_error_tokenizing("invalid argument 2", parse->token->line, \
											parse->token->col);
}

void	check_instruction(t_parser *parse)
{
	char *content;

	content = parse->token->content;
	if (!ft_strcmp(content, "live") || !ft_strcmp(content, "zjmp") ||
		!ft_strcmp(content, "fork") || !ft_strcmp(content, "lfork"))
		live_zjmp_fork_lfork(parse);
	else if (!ft_strcmp(content, "ld") || !ft_strcmp(content, "lld"))
		ld_lld(parse);
	else if (!ft_strcmp(content, "st"))
		st(parse);
	else if (!ft_strcmp(content, "add") || !ft_strcmp(content, "sub"))
		add_sub(parse);
	else if (!ft_strcmp(content, "and") || !ft_strcmp(content, "or") || \
													!ft_strcmp(content, "xor"))
		and_or_xor(parse);
	else if (!ft_strcmp(content, "ldi") || !ft_strcmp(content, "lldi"))
		ldi_lldi(parse);
	else if (!ft_strcmp(content, "sti"))
		sti(parse);
	else if (!ft_strcmp(content, "aff"))
		aff(parse);
	else
		throw_error_tokenizing("ivalid instruction", parse->token->line, \
													parse->token->col);
}

void	parse_arguments(t_parser *parse)
{
	parse->iter = 0;
	parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
	while (parse->iter < parse->tokens->size)
	{
		if (parse->token->type == INSTRUCTION)
			check_instruction(parse);
		parse->token = (*(t_token**)ft_vat(parse->tokens, \
													++(parse->iter)));
	}
}
