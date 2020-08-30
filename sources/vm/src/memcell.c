/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:48:17 by adavis            #+#    #+#             */
/*   Updated: 2019/11/01 19:40:48 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	memcell_set(t_corewar *cw, int i, int value, int champ_id)
{
	cw->arena[i % MEM_SIZE].value = value;
	cw->arena[i % MEM_SIZE].champ_id = champ_id;
}
