/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:04:36 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/19 19:19:17 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_start(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;
	char	boolean;

	boolean = 'T';
	count = 0;
	i = 0;
	while (s1[i] && boolean == 'T')
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				boolean = 'T';
				break ;
			}
			boolean = 'F';
			j++;
		}
		i++;
	}
	return (count);
}

static int		ft_end(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;
	char	boolean;

	boolean = 'T';
	count = 0;
	i = ft_strlen(s1) - 1;
	while (i > 0 && boolean == 'T')
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				boolean = 'T';
				break ;
			}
			boolean = 'F';
			j++;
		}
		i--;
	}
	return (count);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		start;
	size_t		end;
	size_t		size;
	int			i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	else if ((str = (char*)malloc((ft_strlen(s1)
	- start - end + 1) * sizeof(char))) == 0)
		return (0);
	size = ft_strlen(s1) - end;
	while (start < size && s1[start])
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
