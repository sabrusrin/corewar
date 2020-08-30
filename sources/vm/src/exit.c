/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:31:06 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/16 20:08:41 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

int		exit_fail(t_vm *v, t_param *param_tab, int free_list)
{
	if (param_tab)
		free(param_tab);
	if (v)
	{
		if (free_list)
			free_proc_list(v);
		free(v);
	}
	exit(EXIT_FAILURE);
	return (-1);
}
