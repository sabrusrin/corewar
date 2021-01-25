/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:26:48 by chermist          #+#    #+#             */
/*   Updated: 2020/06/24 18:16:22 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t lsrc;

	if (src && dst)
	{
		i = 0;
		lsrc = ft_strlen(src);
		while (i < len)
		{
			if (i < lsrc)
				dst[i] = src[i];
			else
				dst[i] = '\0';
			i++;
		}
	}

	return (dst);
}
