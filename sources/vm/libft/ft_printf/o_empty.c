/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_empty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:11:10 by adavis            #+#    #+#             */
/*   Updated: 2019/09/04 20:14:52 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		o_empty(t_params *params)
{
	size_t	i;

	if (!params->alternate)
	{
		i = 0;
		while (i++ < params->width)
			ft_putchar(' ');
		return (params->width);
	}
	else
	{
		ft_putchar('0');
		return (1);
	}
}
