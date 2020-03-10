/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:00:35 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/08 13:00:39 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char *ptraux;

	ptraux = (unsigned char*)ptr;
	while (len-- > 0)
		*(ptraux++) = (unsigned char)c;
	return (ptr);
}
