/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:27:54 by adavis            #+#    #+#             */
/*   Updated: 2019/09/06 12:20:45 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		perc_render(t_params *params)
{
	int		i;

	i = 1;
	if (params->left)
		ft_putchar('%');
	while (i++ < (int)params->width)
		ft_putchar(params->zeros && !params->left ? '0' : ' ');
	if (!params->left)
		ft_putchar('%');
	if (params->width > 1)
		return ((int)params->width);
	return (1);
}
