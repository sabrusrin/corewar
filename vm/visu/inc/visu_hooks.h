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
*	This function should be called at the beginning of game. It will initialize
*	the field, champions, heads and the visualizer itself. The heads will be
*	automatically, so there's no need to explicitly call init_heads().
*
*	champ_names: names of champions in order (like champ_names[0] contains the
*	name of champ with id 1)
*	field: initial state of the field (size of MEM_SIZE)
*
*	return: 1 on success, 0 on crash
*/
int				init_field(char **champ_names, unsigned char *field);

/*
*	This function should be called when a new head appears on field.
*
*	champ_id: id (1 - MAX_PLAYERS) of champ the head belongs to
*	position: position on field (0 - MEM_SIZE-1)
*
*	return: head id on success, 0 on crash
*/
int				init_head(int champ_id, int position);

/*
*	id: head id received from init_head()
*	new_position: target position on field (0 - MEM_SIZE-1)
*
*	return: 1 on success, 0 on crash
*/
int				move_head(int id, int new_position);

/*
*	id: head id received from init_head()
*
*	return: 1 on success, 0 on crash
*/
int				destroy_head(int id);

/*
*	cell: position of cell on field (0 - MEM_SIZE-1)
*	value: new value
*
*	return: 1 on success, 0 on crash
*/
int				update_cell_value(int cell, unsigned char value);

/*
*	cell: position of cell on field 0 - MEM_SIZE-1)
*	champ_id: id (1 - MAX_PLAYERS) of champ the head will now belong to
*
*	return: 1 on success, 0 on crash
*/
int				update_cell_owner(int cell, int champ_id);

/*
*	champ_id: id (1 - MAX_PLAYERS) of champ the head belongs to
*	last_live: last cycle in which the champ performed live operation
*	lives_in_period: total number of 'live's in current period
*
*	return: 1 on success, 0 on crash
*/
int				update_lives(int champ_id, int last_live, int lives_in_period);