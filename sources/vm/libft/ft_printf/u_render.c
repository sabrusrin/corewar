/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:27:00 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 16:10:07 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	u_nbrlen(unsigned long nbr)
{
	size_t	cnt;

	cnt = 1;
	while (nbr /= 10)
		cnt++;
	return (cnt);
}

int		u_count_len(unsigned long long u, t_params *params)
{
	size_t			len;
	unsigned long	tmp;

	tmp = u;
	len = 1;
	while (tmp /= 10)
		len++;
	if (params->width > len)
		len += params->width - len;
	if (params->precision > (int)len)
		len = params->precision;
	return (len);
}

void	u_render_left(unsigned long long u, t_params *params)
{
	if (params->width)
	{
		ft_putnbr_base(u, 10, false);
		while ((int)(params->width--) - (int)u_nbrlen(u) > 0)
			ft_putchar(' ');
	}
	else
		ft_putnbr_base(u, 10, false);
}

void	u_render_right(unsigned long long u, t_params *params)
{
	if (params->zeros)
	{
		while ((int)(params->width--) - (int)u_nbrlen(u) > 0)
			ft_putchar('0');
		ft_putnbr_base(u, 10, false);
	}
	else
	{
		while ((int)(params->width--) - params->precision > 0)
			ft_putchar(' ');
		while (params->precision-- - (int)u_nbrlen(u) > 0)
			ft_putchar('0');
		ft_putnbr_base(u, 10, false);
	}
}

int		u_render(unsigned long long u, t_params *params)
{
	int		len;

	if (params->prec && !params->precision && u == 0)
		return (o_empty(params));
	len = u_count_len(u, params);
	if (params->prec)
		params->zeros = false;
	if ((int)u_nbrlen(u) > params->precision)
		params->precision = (int)u_nbrlen(u);
	if (params->left)
		u_render_left(u, params);
	else
		u_render_right(u, params);
	return (len);
}
