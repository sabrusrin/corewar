/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:17:23 by adavis            #+#    #+#             */
/*   Updated: 2019/04/25 16:34:14 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*sn;
	size_t	i;

	if (!s || !f)
		return (0);
	if (!(sn = malloc(ft_strlen(s) * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		sn[i] = (*f)(s[i]);
		i++;
	}
	sn[i] = '\0';
	return (sn);
}
