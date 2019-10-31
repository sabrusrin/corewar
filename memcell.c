/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:48:17 by adavis            #+#    #+#             */
/*   Updated: 2019/10/31 13:45:27 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	memcell_set(t_corewar *cw, int i, int value, int player_id) {
	cw->arena[i % MEM_SIZE].value = value;
	cw->arena[i % MEM_SIZE].player_id = player_id;
}
