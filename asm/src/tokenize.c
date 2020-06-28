/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:56:38 by chermist          #+#    #+#             */
/*   Updated: 2020/06/28 21:20:12 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int string_len(char **carriage, char delim)
{
	int	i;

	i = 0;
	while ((*carriage)[i] && (*carriage)[i] != delim)
		i++;
	if (i == 0)
		return (0);
	return (i - 1);
}

t_token *token_create(t_parser *parse_struct, unsigned char op_code, char *type, char *content)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		throw_error("error: Can't allocate memory");
	token->line = parse_struct->line;
	token->col = parse_struct->col;
	token->op_code = op_code;
	if (!(token->type = ft_strdup(type)))
		throw_error("error: Can't allocate memory");
	if (!(token->content = ft_strdup(content)))
		throw_error("error: Can't allocate memory");

	return token;
}

void champ_name_comment_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;

	ft_printf("\n%s\n", *carriage);
	if (!(ft_strnstr(*carriage, NAME_CMD_STRING, 5)))
	{
		ft_putstr(NAME_CMD_STRING);
		token = token_create(parse_struct, 0, "NAME", NAME_CMD_STRING);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		*carriage += 5;
		parse_struct->col += 5;
	}
	else if (!(ft_strnstr(*carriage, COMMENT_CMD_STRING, 8)))
	{
		ft_putstr(COMMENT_CMD_STRING);
		token = token_create(parse_struct, 0, "COMMENT", COMMENT_CMD_STRING);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		*carriage += 8;
		parse_struct->col += 8;
	}
	else
		throw_error("error: Incorrect champion command");
}

void string_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;
	char	*string;
	int		len;

	ft_putchar('@');
	(*carriage)++;
	len = string_len(carriage, '"');
	if (len && (*carriage)[len])
	{
		if (!(string = ft_strndup(*carriage, len)))
			throw_error("error: Can't allocate memory");
		ft_putstr(string);
		token = token_create(parse_struct, 0, "STRING", string);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		ft_strdel(&string);
		*carriage += len + 1;
		parse_struct->col += len + 1;
	}
	else
		throw_error_tokenizing("Missing trailing quotation mark", parse_struct->line, parse_struct->col);
}

void comment_skip(t_parser *parse_struct, char **carriage)
{
	while (*carriage)
	{
		(*carriage)++;
		parse_struct->col++;
	}
}

void separator_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;

	token = token_create(parse_struct, 0, "SEPARATOR", ",");
	ft_putchar(',');
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	(*carriage)++;
	parse_struct->col++;
}

void direct_label_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;
	char	*content;
	int		i;

	(*carriage)++;
	i = 0;
	while ((*carriage[i]) && ft_strchr(LABEL_CHARS, (*carriage)[i]))
		i++;
	if (i > 0)
	{
		if (!(content = ft_strndup(*carriage, i)))
			throw_error("error: Can't allocate memory");
		token = token_create(parse_struct, 0, "DIRECT_LABEL", content);
		ft_putstr(content);
		ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
		ft_strdel(&content);
		(*carriage) += i;
		parse_struct->col += i;
	}
}

void direct_token_create(t_parser *parse_struct, char **carriage)
{
	t_token	*token;
	char	*content;
	int		i;

	carriage++;
	i = 0;
	while ((*carriage)[i] && (*carriage)[i] == '-')
		i++;
	while ((*carriage)[i] && ft_isdigit((*carriage)[i]))
		i++;
	if (!(content = ft_strndup(*carriage, i)))
		throw_error("error: Can't allocate memory");
	token = token_create(parse_struct, 0, "DIRECT", content);
		ft_putstr(content);
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	ft_strdel(&content);
	(*carriage) += i;
	parse_struct->col += i;
}

void indirect_label_token_create(t_parser *parse_struct, char **carriage)
{
	t_token *token;
	char	*content;
	int		i;

	i = 0;
	i = string_len(carriage, ':');


}

void label_token(t_parser *parse_struct, char **carriage)
{
	t_token	*token;
	char	*content;
	int		i;

	i = 0;
	i = string_len(carriage, ':');
	if (!(content = ft_strndup(*carriage, i)))
		throw_error("error: Can't allocate memory");
	token = token_create(parse_struct, 0, "LABEL", content);
		ft_putstr(content);
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	ft_strdel(&content);
	(*carriage) += i;
	parse_struct->col += i;
}

void register_token(t_parser *parse_struct, char **carriage, int i)
{
	t_token	*token;
	char	*content;

	i -= parse_struct->col + 1;
	if (!(content = ft_strndup(*carriage, i)))
		throw_error("error: Can't allocate memory");
	token = token_create(parse_struct, 0, "REGISTER", content);
		ft_putstr(content);
	ft_vpush_back(parse_struct->tokens, &token, sizeof(t_token**));
	ft_strdel(&content);
	(*carriage) += i;
	parse_struct->col += i;
}

void instruction_token(t_parser *parse_struct, char **carriage, int i)
{
	t_token	*token;
	char	*content;

	i -= parse_struct->col + 1;
	if (!(content = ft_strndup(*carriage, i)))
		throw_error("error: Can't allocate memory");
	token = token_create(parse_struct, 0, "INSTRUCTION", content);
		ft_putstr(content);
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
	{
		if (digit_counter == 0)
			label_token(parse_struct, carriage);
	}
	else if (!(*carriage)[i] || (*carriage)[i] == ' ' || (*carriage)[i] == '\t' ||
			(*carriage)[i] == '-' || (*carriage)[i] == SEPARATOR_CHAR ||
			(*carriage)[i] == DIRECT_CHAR)
	{
		if (**carriage == 'r' &&
				(((i - parse_struct->col) == 2 && digit_counter == 1) ||
				((i - parse_struct->col) == 3 && digit_counter == 2)))
			register_token(parse_struct, carriage, i);
		instruction_token(parse_struct, carriage, i);
	}
}

void parse_token(t_parser *parse_struct, char **carriage)
{
	if (**carriage == COMMAND_CHAR)
		champ_name_comment_token_create(parse_struct, carriage);
	else if (**carriage == '\"')
		string_token_create(parse_struct, carriage);
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
		label_instr_reg_token_create(parse_struct, carriage);
	// else if (**carriage == LABEL_CHAR)
		// indirect_label_token_create(parse_struct, carriage);
	
}

void tokenize(t_parser *parse_struct)
{
	char	*line;

	while (parse_struct->line < parse_struct->buffer->size)
	{
		parse_struct->col = 0;
		line = *((char**)ft_vat(parse_struct->buffer, parse_struct->line));
		ft_putendl(line);
		while (*line != '\0')
		{
			ft_putchar('k');
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
