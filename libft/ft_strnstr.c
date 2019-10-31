/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:07:54 by adavis            #+#    #+#             */
/*   Updated: 2019/04/25 16:35:24 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0 &&
			ft_strlen(needle) <= len - i)
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
