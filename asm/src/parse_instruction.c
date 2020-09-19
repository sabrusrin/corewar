/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:51:58 by chermist          #+#    #+#             */
/*   Updated: 2020/09/18 00:20:25 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_arg(t_token *arg)
{
	if (arg->type == REGISTER || arg->type == DIRECT_LABEL ||
		arg->type == DIRECT || arg->type == INDIRECT_LABEL ||
		arg->type == INDIRECT)
		return (1);
	return (0);
}

void	parse_instruction(t_parser *parse)
{
	t_token	*arg;
	t_token	*tmp;
	t_token *next;

	arg = take_next_token(parse);
	if (is_arg(arg))
		ft_vpush_back(parse->token->args, &arg, sizeof(t_token**));
	else
		throw_error_tokenizing("bad instruction argument", arg->line, arg->col);
	tmp = *(t_token**)ft_vat(parse->tokens, parse->iter + 1);
	next = *(t_token**)ft_vat(parse->tokens, parse->iter + 2);
	if (tmp->type == SEPARATOR && is_arg(next))
	{
		parse->iter++;
		return (parse_instruction(parse));
	}
}
