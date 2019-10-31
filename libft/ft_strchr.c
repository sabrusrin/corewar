/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:34:20 by adavis            #+#    #+#             */
/*   Updated: 2019/05/01 18:31:11 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_iter;

	s_iter = (char *)s;
	while (*s_iter)
	{
		if (*s_iter == (char)c)
			return (s_iter);
		s_iter++;
	}
	if (*s_iter == (char)c)
		return (s_iter);
	return (NULL);
}
