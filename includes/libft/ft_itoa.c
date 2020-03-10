/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:50:10 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/19 18:34:18 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(long int n)
{
	int size;

	size = 0;
	if (n < 0)
		n = n * -1;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

static void	ft_strrev(char *str)
{
	int		i;
	int		count;
	char	tmp;

	count = 0;
	i = -1;
	while (str[count])
		count++;
	count--;
	while (i++ < count / 2)
	{
		tmp = str[i];
		str[i] = str[count - i];
		str[count - i] = tmp;
	}
}

static char	*ft_intoa(char *str, long int n, int size)
{
	int i;

	i = 0;
	while (n >= 10)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	str[i] = n + '0';
	str[size] = 0;
	return (str);
}

char		*ft_itoa(int b)
{
	char		*str;
	int			size;
	long int	n;

	n = b;
	size = ft_count_size(n);
	if (n < 0)
		size++;
	if ((str = (char *)malloc((size + 1) * sizeof(char))) == 0)
		return (0);
	if (n < 0)
	{
		str[size - 1] = '-';
		n = n * -1;
	}
	str = ft_intoa(str, n, size);
	ft_strrev(str);
	return (str);
}
