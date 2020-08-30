/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:38:55 by adavis            #+#    #+#             */
/*   Updated: 2018/12/10 16:42:38 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	unsigned char	*mem_fill;

	if (!(mem = (unsigned char *)malloc(size)))
		return (NULL);
	mem_fill = mem;
	while (size--)
	{
		*mem_fill = 0;
		mem_fill++;
	}
	return (mem);
}
