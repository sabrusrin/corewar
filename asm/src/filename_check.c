/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:07:09 by chermist          #+#    #+#             */
/*   Updated: 2020/06/20 17:18:27 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int check_filename(const char *filename, const char *suffix)
{
	int name_len;
	int suffix_len;

	if (filename && suffix)
	{
		if (ft_strstr(filename, suffix))
		{
			name_len = ft_strlen(filename);
			suffix_len = ft_strlen(suffix) - 1;
			if (ft_strcmp(filename + (name_len - suffix_len), suffix))
				return (1);
		}
	}

	return (0);
}