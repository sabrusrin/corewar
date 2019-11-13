/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 18:52:40 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_nbrlen(unsigned long long nbr)
{
	int		cnt;

	cnt = 1;
	while (nbr /= 16)
		cnt++;
	return (cnt);
}

size_t	p_count_len(unsigned long long d, t_params *params)
{
	size_t				len;
	unsigned long long	tmp;

	tmp = d;
	len = 1;
	while (tmp /= 16)
		len++;
	len += 2;
	if (params->width > len)
		len = (int)params->width;
	if (params->precision + 2 > (int)len)
		len = params->precision + 2;
	return (len);
}

void	p_render_left(unsigned long long d, t_params *params)
{
	if (params->width)
	{
		ft_putstr("0x");
		ft_putnbr_base(d, 16, false);
		while ((int)(params->width--) - p_nbrlen(d) - 2 > 0)
			ft_putchar(' ');
	}
	else
	{
		ft_putstr("0x");
		ft_putnbr_base(d, 16, false);
	}
}

void	p_render_right(unsigned long long d, t_params *params)
{
	if (params->zeros)
	{
		ft_putstr("0x");
		while ((int)(params->width--) - p_nbrlen(d) - 2 > 0)
			ft_putchar(params->zeros ? '0' : ' ');
		ft_putnbr_base(d, 16, false);
	}
	else
	{
		while ((int)(params->width--) - p_nbrlen(d) - 2 > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		while (params->precision-- - p_nbrlen(d) > 0)
			ft_putchar('0');
		ft_putnbr_base(d, 16, false);
	}
}

int		p_render(unsigned long long d, t_params *params)
{
	size_t	len;

	if (params->prec && !params->precision && d == 0)
	{
		ft_putstr("0x");
		return (2);
	}
	len = p_count_len(d, params);
	if (params->left)
		p_render_left(d, params);
	else
		p_render_right(d, params);
	return (len);
}
