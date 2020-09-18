/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:49:51 by chermist          #+#    #+#             */
/*   Updated: 2020/09/19 00:41:11 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void if_direct(t_parser *parse, t_token *arg, int arg_num)
{
	arg->byte_number = parse->current_byte;
	arg->byte_size = parse->token->t_dir_size;
	parse->current_byte += parse->token->t_dir_size;
	if (arg_num == 1 && parse->token->args_code)
		parse->token->args_code += 127;
	else if (arg_num == 2 && parse->token->args_code)
		parse->token->args_code += 32;
	else if (arg_num == 3 && parse->token->args_code)
		parse->token->args_code += 8;
}

void if_indirect(t_parser *parse, t_token *arg, int arg_num)
{
	arg->byte_number = parse->current_byte;
	arg->byte_size = 2;
	parse->current_byte += 2;
	if (arg_num == 1 && parse->token->args_code)
		parse->token->args_code += 191;
	else if (arg_num == 2 && parse->token->args_code)
		parse->token->args_code += 48;
	else if (arg_num == 3 && parse->token->args_code)
		parse->token->args_code += 12;
}

void if_register(t_parser *parse, t_token *arg, int arg_num)
{
	arg->byte_number = parse->current_byte;
	arg->byte_size = 1;
	parse->current_byte += 1;
	if (arg_num == 1 && parse->token->args_code)
		parse->token->args_code += 63;
	else if (arg_num == 2 && parse->token->args_code)
		parse->token->args_code += 16;
	else if (arg_num == 3 && parse->token->args_code)
		parse->token->args_code += 4;
}

void get_op_weight(t_parser *parse, unsigned char op_code, int t_dir_size, \
												unsigned char args_code)
{
	t_token	*arg;
	int		arg_i;

	parse->token->op_code = op_code;
	parse->token->byte_number = parse->current_byte;
	parse->token->t_dir_size = t_dir_size;
	parse->token->args_code = args_code;
	parse->current_byte += 1;
	if (args_code)
		parse->current_byte++;
	arg_i = 0;
	while (arg_i < parse->token->args->size)
	{
		arg = *(t_token**)ft_vat(parse->token->args, arg_i);
		if (arg->type == INDIRECT || arg->type == INDIRECT_LABEL)
			if_indirect(parse, arg, ++arg_i);
		if (arg->type == DIRECT || arg->type == DIRECT_LABEL)
			if_direct(parse, arg, ++arg_i);
		else
			if_register(parse, arg, ++arg_i);
	}
	parse->token->byte_size = parse->current_byte - \
										parse->token->byte_number - 1;
}

void put_operation_weight(t_parser *parse)
{
	if (!ft_strcmp(parse->token->content, "live"))
		get_op_weight(parse, 0x01, 4, 0);
	else if (!ft_strcmp(parse->token->content, "ld"))
		get_op_weight(parse, 0x02, 4, 1);
	else if (!ft_strcmp(parse->token->content, "st"))
		get_op_weight(parse, 0x03, 4, 1);
	else if (!ft_strcmp(parse->token->content, "add"))
		get_op_weight(parse, 0x04, 4, 1);
	else if (!ft_strcmp(parse->token->content, "sub"))
		get_op_weight(parse, 0x05, 4, 1);
	else if (!ft_strcmp(parse->token->content, "and"))
		get_op_weight(parse, 0x06, 4, 1);
	else if (!ft_strcmp(parse->token->content, "or"))
		get_op_weight(parse, 0x07, 4, 1);
	else if (!ft_strcmp(parse->token->content, "xor"))
		get_op_weight(parse, 0x08, 4, 1);
	else if (!ft_strcmp(parse->token->content, "zjmp"))
		get_op_weight(parse, 0x09, 2, 0);
	else if (!ft_strcmp(parse->token->content, "ldi"))
		get_op_weight(parse, 0x0a, 2, 1);
	else if (!ft_strcmp(parse->token->content, "sti"))
		get_op_weight(parse, 0x0b, 2, 1);
	else if (!ft_strcmp(parse->token->content, "fork"))
		get_op_weight(parse, 0x0c, 2, 0);
	else if (!ft_strcmp(parse->token->content, "lld"))
		get_op_weight(parse, 0x0d, 4, 1);
	else if (!ft_strcmp(parse->token->content, "lldi"))
		get_op_weight(parse, 0x0e, 2, 1);
	else if (!ft_strcmp(parse->token->content, "lfork"))
		get_op_weight(parse, 0x0f, 2, 0);
	else if (!ft_strcmp(parse->token->content, "aff"))
		get_op_weight(parse, 0x10, 4, 1);
}


void calc_size(t_parser *parse)
{
	parse->iter = 0;
	parse->token = *(t_token**)ft_vat(parse->tokens, parse->iter);
	while (parse->iter < parse->tokens->size)
	{
		if (parse->token->type == INSTRUCTION)
		{
			parse->token->byte_number = parse->current_byte;
			parse->token->byte_size = 1;
			put_operation_weight(parse);
		}
		parse->token = (*(t_token**)ft_vat(parse->tokens, \
													++(parse->iter)));
	}
}