/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:10:31 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/08 13:12:16 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	int		i;
	size_t	len;

	len = 0;
	srclen = ft_strlen(src);
	if (dstsize < ft_strlen(dst))
		return (srclen + dstsize);
	while (dst[len] && len < dstsize)
		len += 1;
	i = len;
	srclen = ft_strlen(src);
	while (src[len - i] && len < dstsize - 1)
	{
		dst[len] = src[len - i];
		len++;
	}
	dst[len] = 0;
	return (srclen + i);
}
