/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:30:27 by adavis            #+#    #+#             */
/*   Updated: 2019/04/25 16:36:39 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ss;
	char	*s_start;
	char	*s_new;
	size_t	i;

	if (!s)
		return (NULL);
	ss = (char *)s;
	while (*ss == ' ' || *ss == '\n' || *ss == '\t')
		ss++;
	s_start = ss;
	i = ft_strlen(ss);
	ss += ft_strlen(ss) - 1;
	while ((*ss == ' ' || *ss == '\n' || *ss == '\t') && i > 0)
	{
		i--;
		ss--;
	}
	if (!(s_new = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	ft_strncpy(s_new, s_start, i);
	*(s_new + i) = '\0';
	return (s_new);
}
