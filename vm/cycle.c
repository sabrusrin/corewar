/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:12:01 by adavis            #+#    #+#             */
/*   Updated: 2019/11/04 18:45:31 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cycle(t_corewar *cw)
{
	t_head	*head;

	head = cw->heads;
	while (head)
	{
		// set operation code
		if (head->to_op > 0)
			head->to_op--;
		else
		{
			// if op_code and reg is valid -> execute
		}
		head = head->next;
	}
	//if (!(cw->cycles_passed % cw->cycles_to_die))
	//	check();
}
