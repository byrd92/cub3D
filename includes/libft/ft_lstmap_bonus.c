/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:57:20 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/15 14:01:25 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *list;
	t_list *new;

	list = NULL;
	if (lst && f)
	{
		list = ft_lstnew(f(lst->content));
		lst = lst->next;
		while (lst)
		{
			if (!(new = ft_lstnew(f(lst->content))))
			{
				ft_lstdelone(list, del);
				return (NULL);
			}
			ft_lstadd_back(&list, new);
			lst = lst->next;
		}
		return (list);
	}
	return (NULL);
}
