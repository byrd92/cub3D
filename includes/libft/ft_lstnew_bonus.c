/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:27:41 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/14 14:09:09 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*aux;

	aux = malloc(sizeof(t_list));
	if (aux == NULL)
		return (0);
	if (content == NULL)
	{
		aux->content = NULL;
		aux->next = NULL;
		return (aux);
	}
	else
	{
		aux->content = content;
		aux->next = NULL;
		return (aux);
	}
}
