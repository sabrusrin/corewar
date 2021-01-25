/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:56:38 by chermist          #+#    #+#             */
/*   Updated: 2020/07/01 15:33:05 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void champ_name_comment_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;

	if (ft_strnstr(*carriage, NAME_CMD_STRING, 5))
	{
		token = token_create(parse_struct, "NAME", NAME_CMD_STRING);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		*carriage += 5;
		parse_struct->col += 5;
	}
	else if (ft_strnstr(*carriage, COMMENT_CMD_STRING, 8))
	{
		token = token_create(parse_struct, "COMMENT", COMMENT_CMD_STRING);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		*carriage += 8;
		parse_struct->col += 8;
	}
	else
		throw_error_tokenizing("Incorrect champion command", \
								parse_struct->line, parse_struct->col);
}

void string_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;
	char	*string;
	int		len;

	(*carriage)++;
	len = string_len(carriage, '"');
	if (len && (*carriage)[len])
	{
		if (!(string = ft_strndup(*carriage, len)))
			throw_error("error: Can't allocate memory");
		token = token_create(parse_struct,"STRING", string);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		ft_strdel(&string);
		*carriage += len + 1;
		parse_struct->col += len + 1;
	}
	else
		throw_error_tokenizing("Missing trailing quotation mark",
										parse_struct->line, parse_struct->col);
}

void parse_token(t_parser *parse_struct, char **carriage)
{
	if (**carriage == COMMAND_CHAR)
		champ_name_comment_token_create(parse_struct, carriage);
	else if (**carriage == '\"')
	{
		string_token_create(parse_struct, carriage);
	}
	else if (**carriage == COMMENT_CHAR || **carriage == ALT_COMMENT_CHAR)
		comment_skip(parse_struct, carriage);
	else if (**carriage == SEPARATOR_CHAR)
		separator_token_create(parse_struct, carriage);
	else if (**carriage == DIRECT_CHAR)
	{
		if (*(*carriage + 1) && *(*carriage + 1) == LABEL_CHAR)
			direct_label_token_create(parse_struct, carriage);
		else if (*(*carriage + 1) && ((*(*carriage + 1) == '-' && \
			ft_isdigit(*(*carriage + 2))) || ft_isdigit(*(*carriage + 1))))
			direct_token_create(parse_struct, carriage);
	}
	else if (ft_strchr(LABEL_CHARS, **carriage))
	{
		label_instr_reg_token_create(parse_struct, carriage);
	}
}

void tokenize(t_parser *parse_struct)
{
	char	*line;

	while (parse_struct->line < parse_struct->buffer->size)
	{
		parse_struct->col = 0;
		line = *((char**)ft_vat(parse_struct->buffer, parse_struct->line));
		while (*line != '\0')
		{
			if (*line == ' ' || *line == '\t')
			{
				line++;
				parse_struct->col++;
			}
			else
				parse_token(parse_struct, &line);
		}
		parse_struct->line++;
	}
}
