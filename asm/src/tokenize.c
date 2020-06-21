/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:56:38 by chermist          #+#    #+#             */
/*   Updated: 2020/06/21 22:14:37 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token *token_create(t_parser *parse_struct, unsigned char op_code, char *type, char *content)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		throw_error("error: Can't allocate memory")
	token->line = parse_struct->line;
	token->col = parse_struct->col;
	token->op_code = op_code;
	token->type = ft_strdup(type);
	token->content = ft_strdup(content);

	return token;
}

void champ_name_comment_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;

	if (!(ft_strnstr(*carriage, NAME_CMD_STRING)))
	{
		token = token_create(parse_struct, 0, "NAME", COMMENT_CMD_STRING);
		ft_vpush_back(&token, sizeof(t_token**))
	}
	else if (!(ft_strnstr(*carriage, COMMENT_CMD_STRING)))
	{
		token = token_create(parse_struct->line, 0, "COMMENT", COMMENT_CMD_STRING);
		ft_vpush_back(&token, sizeof(t_token**))
	}
	else
		throw_error("error: Incorrect champion command");
}

void string_token_create(t_parser *parse_struct, char **carriage)
{

}

void comment_token_create(t_parser *parse_struct, char **carriage)
{

}

void separator_token_create(t_parser *parse_struct, char **carriage)
{

}

void direct_token_create(t_parser *parse_struct, char **carriage)
{

}

void label_token_create(t_parser *parse_struct, char **carriage)
{

}

void label_instr_reg_token_create(t_parser *parse_struct, char **carriage)
{

}

void parse_token(t_parser *parse_struct, char **carriage)
{
	if (**carriage == COMMAND_CHAR)
		champ_name_comment_token_create(parse_struct, carriage);
	else if (**carriage == '\"')
		string_token_create(parese_struct, carriage)
	else if (**carriage == COMMENT_CHAR || **line == ALT_COMMENT_CHAR)
		comment_token_create(parse_struct, carriage);
	else if (**carriage == SEPARATOR_CHAR)
		separator_token_create(parse_struct, carriage);
	else if (**carriage == DIRECT_CHAR)
		direct_token_create(parse_struct, carriage);
	else if (**carriage == LABEL_CHAR)
		label_token_create(parse_struct, carriage);
	else if (ft_strchr(LABEL_CHARS, **carriage))
		label_intstr_reg_token_create(parse_struct, carriage)
}

void tokenize(t_parser *parse_struct)
{
	char	*line;

	while (parse_struct->line < parse_struct->buffer->size)
	{
		line = *((char**)ft_vat(parse_struct->buffer, parse_struct->line));
		while (*line != '\n')
		{
			parse_struct->col++;
			if (*line == ' ' || *line == '\t')
				line++;
			else
				parse_token(parse_struct, &line);
		}
		parse_struct->line++:
	}
}
