/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:56:37 by adavis            #+#    #+#             */
/*   Updated: 2019/05/01 19:29:41 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*str_fill;

	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	str_fill = str;
	while (size--)
	{
		*str_fill = '\0';
		str_fill++;
	}
	*str_fill = '\0';
	return (str);
}
