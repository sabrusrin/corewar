/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:12:01 by adavis            #+#    #+#             */
/*   Updated: 2019/04/17 14:57:26 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *content, size_t content_size)
{
	if (content)
		free(content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*newlst_first;
	t_list	*tmp;

	if (!f || !lst || !(newlst = f(lst)))
		return (NULL);
	newlst_first = newlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp = f(lst)))
		{
			ft_lstdel(&newlst_first, &ft_del);
			return (newlst_first);
		}
		else
		{
			newlst->next = tmp;
			newlst = newlst->next;
		}
	}
	return (newlst_first);
}
