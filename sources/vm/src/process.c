/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:37:55 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/09/03 21:49:46 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static t_process	new_proc(void)
{
	t_process	proc;

	ft_bzero(&proc, sizeof(proc));
	return (proc);
}

static void			set_proc(t_vm *v, t_plist *tmp, int c)
{
	tmp->proc.proc_nb = c + 1;
	tmp->proc.champ = ++v->nb_process;
	tmp->proc.opc = v->f.field[(c * MEM_SIZE / v->nb_players) % MEM_SIZE];
	tmp->proc.pc = (c * MEM_SIZE / v->nb_players) % MEM_SIZE;
	tmp->proc.exec_cycle = v->op_tab[tmp->proc.opc - 1].cycles;
	ft_bzero(tmp->proc.reg, sizeof(char) * REG_NUMBER);
	tmp->proc.reg[0] = v->players[c].nb_champ;
	tmp->proc.champ = c;
	tmp->next = NULL;
}

static int			init_starting_procs(t_vm *v)
{
	t_plist *tmp;
	t_plist	*tmp2;
	int		c;

	tmp = v->process_list;
	tmp->proc = new_proc();
	c = v->nb_players;
	v->nb_process = 0;
	while (--c >= 0)
	{
		set_proc(v, tmp, c);
		if (!(tmp2 = (t_plist*)malloc(sizeof(t_plist))))
		{
			tmp->next = tmp2;
			return (exit_fail(v, NULL,  1));
		}
		tmp2->proc = new_proc();
		tmp2->prev = tmp;
		tmp2->next = NULL;
		tmp->next = tmp2;
		tmp = tmp->next;
	}
	return (1);
}

int					start_proc_list(t_vm *v)
{
	v->process_list = NULL;
	if (!(v->process_list = (t_plist*)malloc(sizeof(t_plist))))
		return (exit_fail(v, NULL, 0));
	v->process_list->prev = NULL;
	v->process_list->next = NULL;
	init_starting_procs(v);
	return (0);
}
