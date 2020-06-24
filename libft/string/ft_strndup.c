/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:50:42 by chermist          #+#    #+#             */
/*   Updated: 2020/06/24 20:00:02 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*cp;
	char	*pcp;

	pcp = NULL;
	if (s1)
	{
		len = ft_strlen(s1);
		if (len > n)
			len = n;
		if (!(cp = ft_strnew(len)))
			return (pcp);
		pcp = cp;
		while (len--)
			*cp++ = *s1++;
	}
	return (pcp);
}
