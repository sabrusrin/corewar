/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:49:33 by adavis            #+#    #+#             */
/*   Updated: 2019/04/25 16:27:13 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char	*s1_iter;
	char	*s2_iter;

	s1_iter = (char *)s1;
	s2_iter = (char *)s2;
	while (*s1_iter || *s2_iter)
	{
		if (*s1_iter != *s2_iter)
			return ((unsigned char)*s1_iter - (unsigned char)*s2_iter);
		s1_iter++;
		s2_iter++;
	}
	return (0);
}
