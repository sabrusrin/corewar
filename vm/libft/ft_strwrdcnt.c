/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwrdcnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:32:32 by adavis            #+#    #+#             */
/*   Updated: 2019/04/25 16:38:07 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strwrdcnt(char *str, char sep)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		if (*str != sep)
		{
			cnt++;
			while (*str != sep && *str)
				str++;
		}
		else
			str++;
	}
	return (cnt);
}
