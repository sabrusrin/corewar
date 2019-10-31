/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:59:48 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 22:08:55 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_params	params;
	char		*fmt;
	char		*ffmt;
	int			len;

	len = 0;
	fmt = ft_strnew(ft_strlen(format) + 1);
	ft_strcpy(fmt, format);
	ffmt = fmt;
	va_start(ap, format);
	while (*fmt)
	{
		if (*fmt == '%')
			len += parse(&fmt, ap, &params);
		else
		{
			ft_putchar(*fmt);
			len++;
		}
		fmt++;
	}
	va_end(ap);
	ft_strdel(&ffmt);
	return (len);
}
