/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:13:17 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 16:18:54 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(long long n)
{
	unsigned long long	num;
	unsigned long long	num2;
	unsigned long long	dvdr;

	if (n < 0)
	{
		ft_putchar('-');
		num = n * -1;
	}
	else
		num = n;
	num2 = num;
	dvdr = 1;
	while (num2 > 9)
	{
		dvdr *= 10;
		num2 /= 10;
	}
	while (dvdr > 0)
	{
		ft_putchar(num / dvdr % 10 + '0');
		dvdr /= 10;
	}
}
