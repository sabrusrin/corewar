/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_render_zeros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:23:17 by adavis            #+#    #+#             */
/*   Updated: 2019/09/04 20:23:18 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_render_zeros(long long d, t_params *params)
{
	if (d < 0)
		ft_putchar('-');
	else if (params->sign)
		ft_putchar('+');
	while ((int)(params->width--) - (int)d_nbrlen(d) - params->space > 0)
		ft_putchar('0');
	ft_putnbr(d >= 0 ? d : -d);
}
