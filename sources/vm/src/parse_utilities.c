/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:07:48 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/02 18:59:42 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	return (1);
}

int		ft_number(int argc, char **argv, t_parse_argv *av)
{
	av->bool = 0;
	av->i++;
	if (av->i >= argc - 1 || (argv[av->i][0] != '-'
		&& !ft_isdigit(argv[av->i][0])) || !ft_isnum(argv[av->i] + 1))
	{
		av->bool = 1;
		av->i--;
		return (-1);
	}
	return (ft_atoi(argv[av->i]));
}

int		wrapper(void *p, char return_error_flag)
{
	ft_memdel(p);
	return (return_error_flag == 1 ? -1 : 0);
}

int32_t	vm_abs(int n)
{
	return (n >= 0 ? n : -n);
}
