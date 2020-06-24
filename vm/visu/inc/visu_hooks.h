/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:15:03 by roma              #+#    #+#             */
/*   Updated: 2020/06/24 16:42:33 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	champ_id: id (1-4) of champ the head belongs to
*	position: position on field (0-4095)
*
*	return: head id on success, 0 on crash
*/
int				init_head(int champ_id, int position);

/*
*	id: head id received from init_head()
*	new_position: target position on field (0-4095)
*
*	return: 1 on success, 0 on crash
*/
int				move_head(int id, int new_position);

/*
*	cell: position of cell on field (0-4095)
*	value: new value
*
*	return: 1 on success, 0 on crash
*/
int				update_cell_value(int cell, unsigned char value);

/*
*	cell: position of cell on field (0-4095)
*	champ_id: id (1-4) of champ the head will now belong to
*
*	return: 1 on success, 0 on crash
*/
int				update_cell_owner(int cell, int champ_id);
