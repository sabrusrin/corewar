/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:32:17 by adavis            #+#    #+#             */
/*   Updated: 2018/12/13 15:34:11 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	unsigned int	num2;
	unsigned int	dvdr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(num / dvdr % 10 + '0', fd);
		dvdr /= 10;
	}
}
