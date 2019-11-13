/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:22:31 by adavis            #+#    #+#             */
/*   Updated: 2019/04/25 16:36:19 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*arr_free(void **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	arr = NULL;
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		wrdcnt;
	size_t	i;
	size_t	j;

	if (!s || !(words = (char **)malloc(sizeof(*words) *
								((wrdcnt = ft_strwrdcnt((char *)s, c)) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	words[wrdcnt] = NULL;
	while (wrdcnt--)
	{
		while (s[j] == c)
			j++;
		if (!(words[i] = ft_strnew(ft_strwrdlen((char *)&s[j], c))))
		{
			return (arr_free((void **)words, i - 1));
		}
		ft_strncpy(words[i], (char *)&s[j], ft_strwrdlen((char *)&s[j], c));
		j += ft_strwrdlen((char *)&s[j], c);
		i++;
	}
	return (words);
}
