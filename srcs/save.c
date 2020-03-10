/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:21:59 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/10 17:53:31 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		int_to_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)(i);
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

int			bmp_header(int fd, t_game *g, int padsize)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (g->mapwidth * 3 * g->mapheight) + (padsize * g->mapheight);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, g->mapwidth);
	int_to_char(header + 22, g->mapheight);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

int			bmp_data(int fd, t_game *g, int padsize)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	y = g->mapheight - 1;
	ft_bzero(zero, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < g->mapwidth)
		{
			pixel = *(g->buff + x + y * g->ren.size_line / 4);
			if (write(fd, &pixel, 3) < 0)
				return (0);
			if (padsize < 0 && write(fd, &zero, padsize) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

int			take_screenshot(t_game *g)
{
	int padsize;
	int fd;

	ft_master(g);
	padsize = (4 - ((int)g->mapwidth * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777
		| O_TRUNC | O_APPEND)) < 0)
		return (0);
	bmp_header(fd, g, padsize);
	bmp_data(fd, g, padsize);
	close(fd);
	return (1);
}

void		check_screenshot(t_game *g, char *argv)
{
	if (ft_strncmp("--save", argv, 7) != 0)
		ft_error("ERROR\nSecond argument wrong. Try --save", g);
	if (!take_screenshot(g))
		ft_error("ERROR\nCouldnt Take Screenshot", g);
}
