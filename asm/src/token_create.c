/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:57:16 by chermist          #+#    #+#             */
/*   Updated: 2020/09/19 09:53:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token *token_create(t_parser *parse_struct, t_type type, char *content)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		throw_error("error: Can't allocate memory");
	token->line = parse_struct->line;
	token->col = parse_struct->col;
	token->type = type;
	if (!(token->content = ft_strdup(content)))
		throw_error("error: Can't allocate memory");
	if (type == INSTRUCTION)
		token->args = ft_vnew(3, sizeof(t_token**));
	token->byte_number = 0;
	token->byte_size = 0;
	token->op_code = 0;
	token->t_dir_size = 0;
	token->args_code = 0;

	return token;
}

void separator_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;

	token = token_create(parse_struct, SEPARATOR, ",");
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	(*carriage)++;
	parse_struct->col++;
}

void direct_label_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;
	char	*content;
	int		i;

	// *carriage += 2;// saving only instruction
	i = 2;
	while ((*carriage)[i] && ft_strchr(LABEL_CHARS, (*carriage)[i]))
		i++;
	if (i > 0)
	{
		if (!(content = ft_strndup(*carriage, i)))
			throw_error("error: Can't allocate memory");
		token = token_create(parse_struct, DIRECT_LABEL, content);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		ft_strdel(&content);
		(*carriage) += i;
		parse_struct->col += i;
	}
	else
		throw_error_tokenizing("empty label", parse_struct->line, \
															parse_struct->col);
}

void direct_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;
	char	*content;
	int		i;

	// (*carriage)++;
	i = 1;
	if ((*carriage)[i] && (*carriage)[i] == '-')
		i++;
	while ((*carriage)[i] && ft_isdigit((*carriage)[i]))
		i++;
	if (!(content = ft_strndup(*carriage, i)))
		throw_error("error: Can't allocate memory");
	token = token_create(parse_struct, DIRECT, content);
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	ft_strdel(&content);
	(*carriage) += i;
	parse_struct->col += i;
}

void label_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;
	char	*content;
	int		i;

	(*carriage)++;
	i = 0;
	while ((*carriage)[i] && ft_strchr(LABEL_CHARS, (*carriage)[i]))
		i++;
	if (i > 0)
	{
		if (!(content = ft_strndup(*carriage, i)))
			throw_error("error: Can't allocate memory");
		token = token_create(parse_struct, INDIRECT_LABEL, content);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		ft_strdel(&content);
		(*carriage) += i;
		parse_struct->col += i;
	}
	else
		throw_error_tokenizing("empty label", parse_struct->line, \
															parse_struct->col);
}
