/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:37:43 by adavis            #+#    #+#             */
/*   Updated: 2019/05/01 18:45:23 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*src_iter;
	char	*dst_start;

	dst_start = dst;
	src_iter = (char *)src;
	while (*src_iter)
	{
		*dst = *src_iter;
		dst++;
		src_iter++;
	}
	*dst = '\0';
	return (dst_start);
}
