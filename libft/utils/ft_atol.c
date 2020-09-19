/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 09:35:04 by chermist          #+#    #+#             */
/*   Updated: 2020/09/19 09:37:46 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long				ft_atol(const char *str)
{
	u_int64_t		res;
	long			sign;
	char			*hd;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	hd = (char*)str;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str++;
		if ((str - hd > 19 || (str - hd == 19 &&
		res > 0x8000000000000000 && ft_isdigit(*str))) && sign == -1)
			return (-9223372036854775807);
		if (str - hd > 19 || (str - hd == 19 &&
		res >= 0x7FFFFFFFFFFFFFFF && ft_isdigit(*str)))
			return (9223372036854775807);
	}
	return ((long)res * sign);
}