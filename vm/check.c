/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:08:46 by adavis            #+#    #+#             */
/*   Updated: 2019/12/07 15:07:09 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// TODO: Написать это !!
int		check(t_corewar *cw)
{
	t_head	*head;

	head = cw->heads;
	while (head)
	{
		if (cw->cycles_passed - head->last_live > cw->cycles_to_die)
		{
			// head is dead -> remove head from list
		}
		head = head->next;
	}
}
