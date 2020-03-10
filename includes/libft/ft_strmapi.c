/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:26:07 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/19 18:44:12 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		if (!(str = (char*)malloc(((i + 1) * sizeof(char)))))
			return (NULL);
		ft_strlcpy(str, s, i + 1);
		i = 0;
		while (s[i])
		{
			str[i] = f(i, str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
