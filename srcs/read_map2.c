/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:38:33 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/10 18:41:18 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_closemap(t_game *g, unsigned int x, unsigned int y)
{
	if (g->worldmap[x][y] == 0)
	{
		if (x == 0 || y == 0 || x == (unsigned int)g->maprow || y ==
			(unsigned int)g->mapcol)
			ft_error("Error\nMap invalid, Borders", g);
		if (g->worldmap[x - 1][y] == 3 || g->worldmap[x][y - 1] == 3 ||
			g->worldmap[x][y + 1] == 3 || g->worldmap[x + 1][y] == 3)
			ft_error("Error\nMap invalid, check", g);
	}
	else if (g->worldmap[x][y] == 3)
	{
		if (x < (unsigned int)g->mapcol - 1 && x != 0 &&
			(g->worldmap[x - 1][y] == 0 ||
				g->worldmap[(int)x < g->maprow - 1 ? x + 1 : x][y] == 0))
			ft_error("Error\nMap invalid, check x", g);
		else if (y < (unsigned int)g->maprow - 1 && y != 0 &&
			(g->worldmap[x][(int)y > g->mapcol - 1 ? y + 1 : y] == 0 ||
				g->worldmap[x][y - 1] == 0))
			ft_error("Error\nMap invalid, check y", g);
	}
	return (0);
}

void		ft_check_error(t_game *g)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	if (g->mapwidth == 0)
		ft_error("Error\nScreen resolution not asigned.", g);
	if (!(g->f_color))
		ft_error("Error\nFloor Color not asigned\n", g);
	if (!(g->c_color) && g->f.texturefloor == 0)
		ft_error("Error\nCeiling Color not asigned\n", g);
	while (x < (unsigned int)g->maprow)
	{
		y = 0;
		while (y < (unsigned int)g->mapcol)
		{
			ft_closemap(g, x, y);
			y++;
		}
		x++;
	}
	if (g->ray.posx == 0)
		ft_error("Error\nStart player not inizialited", g);
}

char		*ft_map2(int x, char *map, t_game *g)
{
	int y;

	y = 0;
	while (y < g->mapcol)
	{
		if (ft_isdigit(*map))
		{
			g->worldmap[x][y] = *map - '0';
			if (*map == '2')
				ft_isspray(g, x, y);
		}
		else if (*map == 'N' || *map == 'W' || *map == 'E' || *map == 'S')
		{
			g->ray.posx == 0 ? ft_set_start(x, y, map, g) :
				ft_error("Error\nInit position duplicated", g);
			g->worldmap[x][y] = 0;
		}
		else
			g->worldmap[x][y] = 3;
		y++;
		if (*map != '\n')
			map++;
	}
	map++;
	return (map);
}

void		ft_read_map(char *file, t_game *g)
{
	int		fd;
	char	*tmp;

	if ((tmp = ft_strchr(file, '.')))
	{
		if ((ft_strncmp(tmp, ".cub", 4)))
			ft_error("Error\nExtension .cub wrong", g);
	}
	else
		ft_error("Error\n Not extension asigned", g);
	fd = open(file, O_RDONLY);
	ft_check_line(fd, g);
	ft_map(g->map, g, g->maprow);
	ft_check_error(g);
	free(g->map);
	g->zbuffer = malloc(sizeof(int *) * g->mapwidth);
}

int			ft_map_read(char *line, t_game *g)
{
	char	*tmp;
	int		tmpcol;

	tmpcol = ft_strlen(line);
	g->mapcol = g->mapcol > tmpcol ? g->mapcol : tmpcol;
	tmp = ft_strjoin(g->map, line);
	free(g->map);
	g->map = ft_strjoin(tmp, "\n");
	g->maprow++;
	free(tmp);
	return (1);
}
