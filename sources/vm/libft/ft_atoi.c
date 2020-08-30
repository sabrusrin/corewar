/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:26:06 by adavis            #+#    #+#             */
/*   Updated: 2019/04/24 16:27:55 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	char		*s;
	long long	nbr;
	int			sign;

	s = (char *)str;
	nbr = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nbr = nbr * 10 + (*s - '0');
		if (nbr != nbr * 10 / 10)
			return (sign ? -1 : 0);
		s++;
	}
	return (int)(sign * nbr);
}
