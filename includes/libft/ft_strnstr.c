/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:15:03 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/12 16:31:50 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	i = 0;
	needle_len = ft_strlen(needle);
	if (ft_strlen(haystack) < needle_len)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	while ((i + needle_len) <= len && *haystack)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
