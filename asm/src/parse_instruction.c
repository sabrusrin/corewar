/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:51:58 by chermist          #+#    #+#             */
/*   Updated: 2020/08/15 08:48:44 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void parse_instruction(t_parser *parse)
{
	t_token	*token;
	t_token	*tmp;

	token = take_next_token(parse);
	if (parse->token->arg && token->type == END_LINE)
		throw_error_tokenizing("unexpected token", token->line, token->col);
	if (token->type != REGISTER || token->type != DIRECT_LABEL ||
		token->type != DIRECT || token->type != INDIRECT_LABEL)
	{
		take_next_token(parse);
		return ;
	}
	if (!parse->token->arg)
		parse->token->arg = token;
	else
	{
		tmp = parse->token->arg;
	}
	


}