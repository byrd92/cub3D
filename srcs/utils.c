/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:47:35 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/10 18:17:32 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			deal_key(t_game *g)
{
	key_movement(g);
	key_rotation(g);
	if (g->key.run)
		g->key.movespeed = 0.1;
	else if (!(g->key.run))
		g->key.movespeed = 0.06;
	if (g->key.esc)
		close_game(g);
	return (1);
}

void		ft_set_start(int x, int y, char *map, t_game *g)
{
	g->ray.posx = x + 0.5;
	g->ray.posy = y + 0.5;
	if (*map == 'N')
	{
		g->ray.dirx = -1;
		g->ray.planey = 0.66;
	}
	else if (*map == 'S')
	{
		g->ray.dirx = 1;
		g->ray.planey = -0.66;
	}
	else if (*map == 'E')
	{
		g->ray.diry = 1;
		g->ray.planex = 0.66;
	}
	else if (*map == 'W')
	{
		g->ray.diry = -1;
		g->ray.planex = -0.66;
	}
	else
		ft_error("ERROR\n Init zone does not match", g);
}

void		ft_error(char *s, t_game *g)
{
	write(2, "\033[1;31m", 8);
	write(2, s, ft_strlen(s));
	g->buff = 0;
	system("killall afplay");
	exit(-1);
}

int			close_game(t_game *g)
{
	int x;

	x = 0;
	while (x < g->maprow)
	{
		free(g->worldmap[x]);
		g->worldmap[x] = NULL;
		x++;
	}
	free(g->worldmap);
	free(g->n_path);
	free(g->so_path);
	system("killall afplay");
	exit(0);
}
