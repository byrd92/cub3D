/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:55:38 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/12 15:27:35 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptr;
	unsigned const char	*ptrs;

	ptr = dst;
	ptrs = src;
	while (n--)
	{
		*(ptr++) = *(ptrs);
		if (*(ptrs++) == (unsigned char)c)
			return (ptr);
	}
	return (0);
}
