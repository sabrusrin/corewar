/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:08:07 by adavis            #+#    #+#             */
/*   Updated: 2019/04/11 18:30:56 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(newstr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str = newstr;
	i = 0;
	while (i++ < (size_t)start)
		s++;
	i = 0;
	while (i++ < len)
	{
		*newstr = *s;
		s++;
		newstr++;
	}
	*newstr = '\0';
	return (str);
}
