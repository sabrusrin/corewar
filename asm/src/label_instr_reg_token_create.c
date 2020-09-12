/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_instr_reg_token_create.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:04:21 by chermist          #+#    #+#             */
/*   Updated: 2020/09/12 15:10:38 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void label_token(t_parser *parse_struct, char **carriage, int i)
{
	t_token	*token;
	char	*content;

	if (!(content = ft_strndup(*carriage, i)))
		throw_error("error: Can't allocate memory");
	token = token_create(parse_struct, LABEL, content);
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	ft_strdel(&content);
	(*carriage) += i + 1;
	parse_struct->col += i;
}

void register_token(t_parser *parse_struct, char **carriage, int i)
{
	t_token	*token;
	char	*content;

	if (!(content = ft_strndup(*carriage, i)))
		throw_error("error: Can't allocate memory");
	token = token_create(parse_struct, REGISTER, content);
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	ft_strdel(&content);
	(*carriage) += i;
	parse_struct->col += i;
}

void instruction_token(t_parser *parse_struct, char **carriage, int i)
{
	t_token	*token;
	char	*content;

	if (!(content = ft_strndup(*carriage, i)))
		throw_error("error: Can't allocate memory");
	token = token_create(parse_struct, INSTRUCTION, content);
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	ft_strdel(&content);
	(*carriage) += i;
	parse_struct->col += i;
}

void label_instr_reg_token_create(t_parser *parse_struct, char **carriage)
{
	int	i;
	int	digit_counter;

	i = 0;
	digit_counter = 0;
	while ((*carriage)[i] && ft_strchr(LABEL_CHARS, (*carriage)[i]))
	{
		if (ft_isdigit((*carriage)[i]))
			digit_counter++;
		i++;
	}
	if ((*carriage)[i] && (*carriage)[i] == LABEL_CHAR)
		label_token(parse_struct, carriage, i);
	else if (!(*carriage)[i] || (*carriage)[i] == ' ' || (*carriage)[i] == '\t'
		|| (*carriage)[i] == '-' || (*carriage)[i] == SEPARATOR_CHAR ||
			(*carriage)[i] == DIRECT_CHAR)
	{
		if (**carriage == 'r' &&
				((i == 2 && digit_counter == 1) ||
				(i == 3 && digit_counter == 2)))
			register_token(parse_struct, carriage, i);
		else
			instruction_token(parse_struct, carriage, i);
	}
}
