/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:46:15 by egarcia-          #+#    #+#             */
/*   Updated: 2019/11/12 16:55:45 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
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
