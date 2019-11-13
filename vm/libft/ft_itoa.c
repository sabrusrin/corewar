/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:52:45 by adavis            #+#    #+#             */
/*   Updated: 2019/04/12 15:16:05 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*str;

	len = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	while (tmp /= 10)
		len++;
	if (n < 0)
	{
		n = -n;
		len += ++tmp;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (tmp)
		str[0] = '-';
	return (str);
}
