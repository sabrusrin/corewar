/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:05:12 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 21:43:30 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_render(char c, t_params *params)
{
	size_t	len;

	len = 1;
	if (params->left)
		ft_putchar(c);
	params->width--;
	while ((int)params->width-- > 0)
	{
		ft_putchar(' ');
		len++;
	}
	if (!params->left)
		ft_putchar(c);
	return (len);
}
