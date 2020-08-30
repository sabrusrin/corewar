/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_render_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:58:31 by adavis            #+#    #+#             */
/*   Updated: 2019/09/22 14:42:01 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		d_render_short(short d)
{
	short	tmp;
	int		div;
	int		len;

	tmp = d;
	div = 1;
	while (tmp / div > 10)
		div *= 10;
	len = 0;
	while (div > 0)
	{
		ft_putchar(d / div % 10 + '0');
		div /= 10;
		len++;
	}
	return (len);
}
