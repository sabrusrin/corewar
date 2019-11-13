/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:03:56 by adavis            #+#    #+#             */
/*   Updated: 2018/12/13 17:07:23 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_str;
	unsigned char	*src_str;

	if (n < 1)
		return (NULL);
	dst_str = (unsigned char *)dst;
	src_str = (unsigned char *)src;
	while (n--)
	{
		*dst_str = *src_str;
		if (*dst_str == (unsigned char)c)
			return (dst_str + 1);
		dst_str++;
		src_str++;
	}
	return (NULL);
}
