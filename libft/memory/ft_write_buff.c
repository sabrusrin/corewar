/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:38:55 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/09/03 22:02:38 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_copy_buff(char buff[], char *line, int *i, int *j)
{
	while (*i < 4096 && line[*j])
	{
		buff[*i] = line[*j];
		*j += 1;
		*i += 1;
	}
}

char		*ft_write_buff(char *line, int *i)
{
	static char	buff[4096];
	int			j;

	j = 0;
	if (*i == -1)
	{
		ft_putendl(buff);
		return (0);
	}
	if (!line)
		return (0);
	if (!*i)
		ft_bzero(buff, 4096);
	ft_copy_buff(buff, line, i, &j);
	if (*i == 4096 && line[j])
	{
		write(1, buff, 4096);
		ft_bzero(buff, 4096);
		*i = 0;
		ft_copy_buff(buff, line, i, &j);
	}
	return (buff);
}
