/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:21:09 by adavis            #+#    #+#             */
/*   Updated: 2019/09/12 15:26:15 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int i)
{
	int	sqrt;

	sqrt = 0;
	while (sqrt <= 46340 && sqrt <= i)
	{
		if (sqrt * sqrt == i)
			return (sqrt);
		else if (sqrt * sqrt > i)
			return (sqrt - 1);
		sqrt++;
	}
	return (-1);
}
