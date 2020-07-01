/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:53:36 by chermist          #+#    #+#             */
/*   Updated: 2020/07/01 19:36:12 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void parse_token(t_parser *parse_struct)
{
	t_token	*token;

	token = parse_struct->token;
	if (ft_strcmp(NAME_CMD_STRING, token->content) && !parse_struct->name)
		save_name(parse_struct);
	else if (ft_strcmp(NAME_CMD_STRING, token->content) && parse_struct->name)
		throw_error_tokenizing("multiple names", token->line, token->col);
	if (ft_strcmp(COMMENT_CMD_STRING, token->content) && !parse_struct->comment)
		save_comment();
}

void parse_tokens(t_parser *parse_struct)
{
	int		i;

	i = 0;
	while (i < parse_struct->tokens->size)
	{
		parse_struct->token = *(t_token**)ft_vat(parse_struct->tokens, i);
		parse_token(parse_struct);
		if (parse_struct->name && parse_struct->comment)
			break ;
	}
}