/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:11:58 by adavis            #+#    #+#             */
/*   Updated: 2018/12/13 16:05:39 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *s)
{
	if (s)
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	write(1, "\n", 1);
}
