/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:27:07 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/08 13:28:38 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (s[i] != (unsigned char)c && i > 0)
		i--;
	if (s[i] == (unsigned char)c)
	{
		return ((char *)&s[i]);
	}
	return (0);
}
