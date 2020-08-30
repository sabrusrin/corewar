/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:34:15 by adavis            #+#    #+#             */
/*   Updated: 2019/09/15 19:28:29 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_chr;
	unsigned char	*src_chr;
	size_t			len_tmp;

	if (dst == src)
		return (dst);
	len_tmp = len;
	dst_chr = (unsigned char *)dst;
	src_chr = (unsigned char *)src;
	if (src > dst)
		return (ft_memcpy(dst, (void *)src, len));
	while (len--)
		dst_chr[len] = src_chr[len];
	return (dst);
}
