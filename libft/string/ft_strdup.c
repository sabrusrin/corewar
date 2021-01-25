/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:25:55 by chermist          #+#    #+#             */
/*   Updated: 2020/06/24 19:56:26 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cp;
	char	*pcp;

	pcp = NULL;
	if (s1)
	{
		len = ft_strlen(s1);
		if (!(cp = malloc(len + 1)))
			return (pcp);
		pcp = cp;
		while (len--)
			*cp++ = *s1++;
		*(cp) = 0;
	}
	return (pcp);
}
