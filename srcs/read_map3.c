/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:09:23 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/10 18:15:31 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_isspray(t_game *g, int x, int y)
{
	g->spray[g->n_spray].posx = x + 0.5;
	g->spray[g->n_spray].posy = y + 0.5;
	g->n_spray++;
}

void		ft_screensize(t_game *g, char *line)
{
	int i;

	i = 1;
	if (g->mapwidth != 0 || g->mapheight != 0)
		ft_error("Error\nR rule duplicated", g);
	while (line[i] == ' ')
		i++;
	g->mapwidth = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	g->mapheight = ft_atoi(&line[i]);
	if (g->mapwidth > 1280 || g->mapwidth < 200 || g->mapheight > 720 ||
	g->mapheight < 200)
	{
		write(1, "Resolution not valid. Setting 2560 x 1440\n", 42);
		g->mapwidth = 2560;
		g->mapheight = 1440;
	}
}

void		ft_path_new_aux(char *line, t_game *g)
{
	int i;

	i = 0;
	if (line[0] == 'E')
	{
		while (line[i] != '.')
			i++;
		if (g->e_path == NULL)
			g->e_path = ft_strdup(&line[i]);
		else
			ft_error("Error\nE path duplicated.", g);
	}
	else if (line[0] == 'F' && line[1] == 'T')
	{
		while (line[i] != '.')
			i++;
		if (g->f.texturefloor == 0)
		{
			g->f.texturefloor = 1;
			g->f_path = ft_strdup(&line[i]);
		}
		else
			ft_error("Error\nPath f duplicated.", g);
	}
}

void		ft_path_new(char *line, t_game *g)
{
	int i;

	i = 0;
	if (line[0] == 'N')
	{
		while (line[i] != '.')
			i++;
		if (g->n_path == NULL)
			g->n_path = ft_strdup(&line[i]);
		else
			ft_error("Error\n N path duplicated.", g);
	}
	else if (line[0] == 'W')
	{
		while (line[i] != '.')
			i++;
		if (g->w_path == NULL)
			g->w_path = ft_strdup(&line[i]);
		else
			ft_error("Error\n W path duplicated.", g);
	}
	else
		ft_path_new_aux(line, g);
}

void		ft_map(char *map, t_game *g, int row)
{
	int x;

	g->worldmap = malloc(sizeof(int *) * row);
	x = 0;
	while (x < g->maprow)
	{
		g->worldmap[x] = malloc(sizeof(int) * g->mapcol);
		map = ft_map2(x, map, g);
		x++;
	}
}
