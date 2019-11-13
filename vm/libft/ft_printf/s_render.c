/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:13:21 by adavis            #+#    #+#             */
/*   Updated: 2019/09/06 12:55:34 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_render(char *s, t_params *params)
{
	int		len;
	char	*str;

	str = NULL;
	if (s == NULL)
	{
		str = ft_strdup("(null)");
		s = str;
	}
	if (params->prec && ft_strlen(s))
	{
		str = ft_strnew(params->precision + 1);
		ft_strncpy(str, s, params->precision);
		s = str;
	}
	len = (ft_strlen(s) > params->width ? ft_strlen(s) : params->width);
	if (params->left)
		ft_putstr(s);
	while ((int)(params->width--) - (int)ft_strlen(s) > 0)
		ft_putchar(' ');
	if (!params->left)
		ft_putstr(s);
	ft_strdel(&str);
	return (len);
}
