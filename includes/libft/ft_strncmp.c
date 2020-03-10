/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:58:38 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/12 16:31:42 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned int	r;

	i = 0;
	while (n > 0 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			r = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
			return (r);
		}
		n--;
		i++;
	}
	return (0);
}
