/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 13:40:56 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 23:01:47 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static void	reset_kills(t_vm *v)
{
	if (v->nb_lives >= NBR_LIVE || v->kill_check == MAX_CHECKS)
	{
		v->cycle_to_die -= CYCLE_DELTA;
		v->kill_check = 0;
		if (v->verbose & 2)
			v->print_cycles_to_die = 1;
	}
	v->nb_lives = 0;
}

static void	proc_kill(t_vm *v, t_plist **l)
{
	t_plist	*tmp;
	t_plist	*new;

	if ((*l)->proc.proc_nb == 0)
	{
		*l = (*l)->next;
		return ;
	}
	tmp = *l;
	new = tmp->next;
	if (tmp->prev)
		tmp->prev->next = (*l)->next;
	else
		v->process_list = v->process_list->next;
	tmp = *l;
	tmp->next->prev = (*l)->prev;
	free((*l));
	*l = new;
}

void		count_alive(t_vm *v, int reset)
{
	t_plist	*tmp;

	if (reset)
		v->nb_proc_alive = 0;
	tmp = v->process_list;
	while (tmp)
	{
		if (tmp->proc.proc_nb)
			v->nb_proc_alive++;
		if (reset)
			tmp->proc.alive = 0;
		tmp = tmp->next;
	}
}

void		cycles_to_die(t_vm *v)
{
	t_plist	*tmp;

	if (v->kill_cycle != v->curr_cycle)
		return ;
	v->curr_alive = 0;
	tmp = v->process_list;
	v->kill_check++;
	while (tmp)
	{
		if (!tmp->proc.alive && tmp->proc.proc_nb)
		{
			if (v->verbose & 8 && tmp->proc.proc_nb)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					tmp->proc.proc_nb,
					v->curr_cycle - tmp->proc.last_turn_alive, v->cycle_to_die);
			proc_kill(v, &tmp);
		}
		else
			tmp = tmp->next;
	}
	count_alive(v, 1);
	reset_kills(v);
	if (v->cycle_to_die > 0)
		v->kill_cycle = v->curr_cycle + v->cycle_to_die;
	else
		v->kill_cycle = v->curr_cycle + 1;
}
