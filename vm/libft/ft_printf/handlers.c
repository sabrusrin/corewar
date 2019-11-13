/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:35:39 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 18:29:36 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_u(va_list ap, t_params *params)
{
	if (params->l == 1)
		return (u_render(va_arg(ap, unsigned long long), params));
	else if (params->l == 2)
		return (u_render(va_arg(ap, unsigned long), params));
	else if (params->h == 1)
		return
		(u_render((unsigned short)va_arg(ap, unsigned int), params));
	else if (params->h == 2)
		return (u_render((unsigned char)va_arg(ap, unsigned int), params));
	else
		return (u_render(va_arg(ap, unsigned int), params));
}

int		handle_d(va_list ap, t_params *params)
{
	if (params->l == 1)
		return (d_render(va_arg(ap, long), params));
	else if (params->l == 2)
		return (d_render(va_arg(ap, long long), params));
	else if (params->h == 1)
		return (d_render((short)va_arg(ap, int), params));
	else if (params->h == 2)
		return (d_render((char)va_arg(ap, int), params));
	else
		return (d_render(va_arg(ap, int), params));
}

int		handle_x(va_list ap, t_params *params, t_bool upper)
{
	if (params->l == 1)
		return (x_render(va_arg(ap, unsigned long), params, upper));
	else if (params->l == 2)
		return (x_render(va_arg(ap, unsigned long long), params, upper));
	else if (params->h == 1)
		return (x_render((unsigned short)va_arg(ap, unsigned int), params,
			upper));
	else if (params->h == 2)
		return (x_render((unsigned char)va_arg(ap, unsigned int), params,
			upper));
	else
		return (x_render(va_arg(ap, unsigned int), params, upper));
}

int		handle_o(va_list ap, t_params *params)
{
	if (params->l == 1)
		return (o_render(va_arg(ap, long), params));
	else if (params->l == 2)
		return (o_render(va_arg(ap, long long), params));
	else if (params->h == 1)
		return (o_render((unsigned short)va_arg(ap, int), params));
	else if (params->h == 2)
		return (o_render((unsigned char)va_arg(ap, int), params));
	else
		return (o_render(va_arg(ap, unsigned int), params));
}

int		handle_f(va_list ap, t_params *params)
{
	if (params->precision == 0)
		params->precision = 6;
	if (params->l == 1)
		return (f_render(va_arg(ap, double), params));
	else if (params->lll)
		return (f_render(va_arg(ap, long double), params));
	else
		return (f_render(va_arg(ap, double), params));
}
