/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:14:01 by chermist          #+#    #+#             */
/*   Updated: 2020/09/19 13:38:59 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_cor_filename(char *filename)
{
	char	*base;
	char	*cor;

	base = ft_strsub(filename, 0, ft_strlen(filename) - 2);
	if (!base)
		throw_error("failed to get basename");
	if (!(cor = ft_strjoin(base, ".cor")))
		throw_error("failed to create filename");
	ft_strdel(&base);
	return (cor);
}

void	create_file(t_parser *parse, char *filename)
{
	char	*cor_filename;
	int		out_len;

	cor_filename = get_cor_filename(filename);
	parse->fd = open(cor_filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (parse->fd == -1)
		throw_error("failed to create .cor file");
	out_len = write(parse->fd, parse->byte_code, parse->code_len - 1);
	if (out_len != parse->code_len - 1)
		throw_error("failed to write code to .cor file");
	ft_printf("Writing output program to %s\n", cor_filename);
	close(parse->fd);
}

int		assemble(char *filename)
{
	t_parser	*parse_struct;
	t_token		*test;
	int			test_i;

	parse_struct = initialize(filename);
	tokenize(parse_struct);
	parse_tokens(parse_struct);
	parse_arguments(parse_struct);
	calc_size(parse_struct);
	translate(parse_struct);
	create_file(parse_struct, filename);
	return (1);
}
