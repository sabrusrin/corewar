/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 18:53:13 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	o_nbrlen(unsigned long long nbr)
{
	size_t		cnt;

	cnt = 1;
	while (nbr /= 8)
		cnt++;
	return (cnt);
}

size_t	o_count_len(unsigned long long o, t_params *params)
{
	size_t				len;
	unsigned long long	tmp;

	tmp = o;
	len = 1;
	while (tmp /= 8)
		len++;
	if (params->alternate && o > 0)
		len++;
	if (params->width > len)
		len += params->width - len;
	if (params->precision > (int)len - (params->alternate) && o > 0)
		len = params->precision;
	return (len);
}

void	o_render_left(unsigned long long o, t_params *params)
{
	int		i;

	if (params->alternate)
		params->width--;
	if (params->width)
	{
		if (params->alternate & !params->prec)
			ft_putchar('0');
		i = 0;
		while (i++ < params->precision - (int)o_nbrlen(o) > 0)
			ft_putchar('0');
		ft_putnbr_base(o, 8, false);
		while ((int)(params->width--) - params->precision > 0)
			ft_putchar(' ');
	}
	else
	{
		while ((int)params->precision-- - (int)o_nbrlen(o) > 0)
			ft_putchar('0');
		ft_putnbr_base(o, 8, false);
	}
}

void	o_render_right(unsigned long long o, t_params *params)
{
	if (params->zeros)
	{
		while ((int)(params->width--) - (int)o_nbrlen(o) > 0)
			ft_putchar('0');
		ft_putnbr_base(o, 8, false);
	}
	else
	{
		while ((int)(params->width--) - params->precision -
														params->alternate > 0)
			ft_putchar(' ');
		if (params->alternate && o > 0 &&
				(params->precision == (int)o_nbrlen(o) || !params->prec))
			ft_putchar('0');
		while ((int)params->precision-- - (int)o_nbrlen(o) > 0)
			ft_putchar('0');
		ft_putnbr_base(o, 8, false);
	}
}

int		o_render(unsigned long long o, t_params *params)
{
	size_t	len;

	if (params->prec && !params->precision && o == 0)
		return (o_empty(params));
	len = o_count_len(o, params);
	if ((int)o_nbrlen(o) > params->precision)
		params->precision = (int)o_nbrlen(o);
	if (params->left)
		o_render_left(o, params);
	else
		o_render_right(o, params);
	return (len);
}
