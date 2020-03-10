/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:13:42 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/08 15:14:37 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *casts;

	casts = (unsigned char*)s;
	while (n > 0)
	{
		if (*casts == (unsigned char)c)
			return (casts);
		casts++;
		n--;
	}
	return (0);
}
