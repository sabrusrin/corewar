/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:20:03 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 21:38:22 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(char **fmt, va_list ap, t_params *params)
{
	set_flags(fmt, params);
	if (**fmt == 'd' || **fmt == 'i')
		return (handle_d(ap, params));
	if (**fmt == 'c')
		return (c_render((char)va_arg(ap, int), params));
	if (**fmt == 's')
		return (s_render(va_arg(ap, char *), params));
	if (**fmt == 'o')
		return (handle_o(ap, params));
	if (**fmt == 'x' || **fmt == 'X')
		return (handle_x(ap, params, **fmt == 'X'));
	if (**fmt == 'p')
		return (p_render(va_arg(ap, unsigned long long), params));
	if (**fmt == 'u')
		return (handle_u(ap, params));
	if (**fmt == 'f')
		return (handle_f(ap, params));
	if (**fmt == '%')
		return (perc_render(params));
	return (0);
}
