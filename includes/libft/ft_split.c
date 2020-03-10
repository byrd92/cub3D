/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:47:53 by byrd              #+#    #+#             */
/*   Updated: 2019/11/19 19:24:25 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int words;
	int i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char		*put_words(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**table;
	int		i;

	i = 0;
	if (s)
	{
		if (!(table = (char**)malloc((count_words(s, c) + 1) * sizeof(char*))))
			return (0);
		while (*s)
		{
			while (*s && *s == c)
				s++;
			if (*s && *s != c)
			{
				table[i] = put_words(s, c);
				i++;
				while (*s && *s != c)
					s++;
			}
		}
		table[i] = NULL;
		return (table);
	}
	return (NULL);
}
