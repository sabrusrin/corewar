/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:32:07 by lkarlon-          #+#    #+#             */
/*   Updated: 2020/08/10 23:33:38 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void	ft_write_zero(int i, int *j)
{
	int	len;

	len = 0;
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	while (len < 4)
	{
		ft_write_buff("0", j);
		len++;
	}
}

char		*ft_convert_hexa(unsigned char n)
{
	static char		str[2];
	unsigned char	i;
	int				len;

	if (!n)
		return ("00");
	len = 0;
	i = n;
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	len += len == 1 ? 1 : 0;
	ft_bzero(&str, 2);
	str[0] = '0';
	while (0 < len--)
	{
		if (n % 16 < 10)
			str[len] = n % 16 + '0';
		else
			str[len] = n % 16 + 'a' - 10;
		n /= 16;
	}
	return (str);
}

static int	ft_fill_buff(int i, int *j)
{
	char	*str;

	ft_write_buff("\n", j);
	ft_write_buff("0x", j);
	ft_write_zero(i, j);
	if (!(str = ft_lltoa_base(i, 16)))
		return (-1);
	ft_write_buff(str, j);
	ft_strdel(&str);
	ft_write_buff(" : ", j);
	return (0);
}

int			ft_dump(t_vm *v)
{
	int		i;
	int		j;
	int		mod;

	i = -1;
	j = 0;
	mod = v->dirty ? 64 : 32;
	while (++i < MEM_SIZE)
	{
		if (!i)
			ft_write_buff("0x0000 : ", &j);
		else if (i && !(i % mod))
		{
			if (ft_fill_buff(i, &j))
				return (-1);
		}
		else if (i && !v->dirty)
			ft_write_buff(" ", &j);
		ft_write_buff(ft_convert_hexa(v->f.field[i]), &j);
		if (v->dirty)
			ft_write_buff(" ", &j);
	}
	j = -1;
	ft_write_buff("\0", &j);
	return (0);
}
