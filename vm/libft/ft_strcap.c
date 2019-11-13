/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:05:37 by adavis            #+#    #+#             */
/*   Updated: 2019/06/10 18:42:46 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcap(const char *str)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = ft_strdup(str);
	if (ft_islower(new_str[i]))
		new_str[i] = ft_toupper(new_str[i]);
	while (new_str[++i])
		if (ft_islower(new_str[i]) && ft_isspace(new_str[i - 1]))
			new_str[i] = ft_toupper(new_str[i]);
	return (new_str);
}
