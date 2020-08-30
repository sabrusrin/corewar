/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:14:09 by adavis            #+#    #+#             */
/*   Updated: 2019/04/25 16:16:39 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_chr;
	unsigned char	*src_chr;

	if (dst == src)
		return (dst);
	dst_chr = (unsigned char *)dst;
	src_chr = (unsigned char *)src;
	while (n--)
	{
		*dst_chr = *src_chr;
		dst_chr++;
		src_chr++;
	}
	return (dst);
}
