/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:12:01 by adavis            #+#    #+#             */
/*   Updated: 2019/11/02 14:58:14 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cycle(t_corewar *cw)
{
	t_head	*heads;

	heads = cw->heads;
	while (heads)
	{
		heads->pos = (heads->pos + 1) % MEM_SIZE;
		heads = heads->next;
	}
}
