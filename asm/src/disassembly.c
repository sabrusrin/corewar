/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_disassembly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 23:54:06 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/24 19:10:11 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

/*
** s_file is t_header exempliar
*/

int	main(int argc, char **argv)
{
	t_header s_file;

	open_close_s_file(argc, argv, &s_file);
	return (0);
}
