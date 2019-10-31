/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:30:11 by adavis            #+#    #+#             */
/*   Updated: 2019/04/25 16:42:23 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	tmp;

	i = 0;
	while (str[i] != '\0')
		i++;
	i -= 1;
	len = i;
	j = 0;
	while (j <= len / 2)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
	str[len + 1] = '\0';
}
