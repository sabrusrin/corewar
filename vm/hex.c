/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:16:27 by adavis            #+#    #+#             */
/*   Updated: 2019/11/01 19:41:15 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*hex_get_string(int fd, int size)
{
	char	buf;
	char	*str;
	int		i;

	str = malloc(size);
	i = -1;
	while (++i < size)
	{
		read(fd, &buf, 1);
		str[i] = buf;
	}
	return (str);
}

int		hex_check_null(int fd)
{
	int		i;
	char	buf;

	i = -1;
	while (++i < 4)
	{
		read(fd, &buf, 1);
		if (buf)
			return (0);
	}
	return (1);
}

int		hex_get_nbr(int fd, int size)
{
	unsigned char	buf;
	int				i;
	int				nbr;

	nbr = 0;
	i = -1;
	while (++i < size)
	{
		nbr *= 0x100;
		read(fd, &buf, 1);
		nbr += buf;
	}
	return (nbr);
}
