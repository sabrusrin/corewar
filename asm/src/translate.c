/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:54 by chermist          #+#    #+#             */
/*   Updated: 2020/09/19 14:21:17 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void put_magic(t_parser *parse, int *pos)
{
	parse->byte_code[(*pos)++] = (char)0x00;
	parse->byte_code[(*pos)++] = (char)0xea;
	parse->byte_code[(*pos)++] = (char)0x83;
	parse->byte_code[(*pos)++] = (char)0xf3;
}

void put_name(t_parser *parse, int *pos)
{
	int i;
	int c;

	i = 0;
	c = *pos;
	while (parse->name[i])
		parse->byte_code[(*pos)++] = parse->name[i++];
	*pos = c + PROG_NAME_LENGTH + 4;
}

void put_comment(t_parser *parse, int *pos)
{
	int i;
	int c;

	i = 0;
	c = *pos;
	while (parse->comment[i])
		parse->byte_code[(*pos)++] = parse->comment[i++];
	*pos = c + COMMENT_LENGTH + 4;
}

void put_code_size(t_parser *parse, int *pos)
{
	unsigned char *byte;
	int i;

	byte = ((unsigned char*)&(parse->current_byte)) + 3;
	i = 0;
	while (i++ < 4)
		parse->byte_code[(*pos)++] = *byte--;
}

void put_num(t_parser *parse, int *pos, t_token *arg, long content)
{
	char			sign;
	unsigned char	*byte;
	int				i;

	sign = 0;
	i = arg->byte_size - 1;
	if (content < 0)
	{
		content *= -1;
		sign = 1;
	}
	content = (sign) ? ~content + 1 : content;
	byte = ((unsigned char*)&content) + i;
	while (i-- >= 0)
		parse->byte_code[(*pos)++] = *byte--;
}

void put_label(t_parser *parse, int *pos, t_token *arg, char *c)
{
	t_token	*tmp;
	t_token	*label;
	t_token	*istr;
	int		iter;
	int		len;
	long	content;

	iter = 0;
	tmp = *(t_token**)ft_vat(parse->tokens, iter);
	len = ft_strlen(c);
	while (iter < parse->tokens->size && (ft_strcmp(tmp->content, c) || \
				(!ft_strcmp(tmp->content, c) && \
				tmp->type != LABEL)))
		tmp = *(t_token**)ft_vat(parse->tokens, ++iter);
	label =  *(t_token**)ft_vat(parse->tokens, iter);
	istr =  *(t_token**)ft_vat(parse->tokens, iter + 1);
	if (iter >= parse->tokens->size)
		throw_error_tokenizing("no label found", parse->token->line, \
															parse->token->col);
	else
	{
		while (iter < parse->tokens->size && tmp->type != INSTRUCTION)
			tmp = *(t_token**)ft_vat(parse->tokens, ++iter);
		content = tmp->byte_number - parse->token->byte_number;
		put_num(parse, pos, arg, content);
	}
}

void put_arg(t_parser *parse, int *pos, t_token *arg)
{
	long content;
	char *c;

	c = arg->content;
	if (*c == 'r' || *c == '%')
		c++;
	if (*c == ':')
		return put_label(parse, pos, arg, ++c);
	content = ft_atol(c);
	put_num(parse, pos, arg, content);
}

void put_commands(t_parser *parse, int *pos)
{
	t_token	*arg;
	int	arg_i;

	parse->iter = 0;
	parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
	while (parse->iter < parse->tokens->size)
	{
		if (parse->token->type == INSTRUCTION)
		{
			parse->byte_code[(*pos)++] = parse->token->op_code;
			if (parse->token->args_code)
				parse->byte_code[(*pos)++] = parse->token->args_code;
			arg_i = 0;
			while (arg_i < parse->token->args->size)
			{
				arg = *(t_token**)ft_vat(parse->token->args, arg_i);
				put_arg(parse, pos, arg);
				arg_i++;
			}
		}
		parse->token = *(t_token**)ft_vat(parse->tokens, ++(parse->iter));
	}
	ft_putnbr(parse->code_len);
}

void translate(t_parser *parse)
{
	int	len;
	int i;
	int current_pos;

	i = 0;
	current_pos = 0;
	len = parse->current_byte + PROG_NAME_LENGTH + COMMENT_LENGTH + 17;
	if (!(parse->byte_code = malloc(len)))
		throw_error("error: Can't allocate memory");
	while (i < len)
		parse->byte_code[i++] = 0;
	parse->code_len = len;

	put_magic(parse, &current_pos);
	put_name(parse, &current_pos);
	put_code_size(parse, &current_pos);
	put_comment(parse, &current_pos);
	put_commands(parse, &current_pos);
}