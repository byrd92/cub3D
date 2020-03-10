/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:33:28 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/05 18:03:37 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			key_pressed(int key, t_keys *k)
{
	if (key == 0)
		k->a = 1;
	else if (key == 1)
		k->s = 1;
	else if (key == 2)
		k->d = 1;
	else if (key == 13)
		k->w = 1;
	else if (key == 123)
		k->left = 1;
	else if (key == 124)
		k->right = 1;
	else if (key == 257)
		k->run = 1;
	else if (key == 53)
		k->esc = 1;
	return (0);
}

int			key_released(int key, t_keys *k)
{
	if (key == 0)
		k->a = 0;
	else if (key == 1)
		k->s = 0;
	else if (key == 2)
		k->d = 0;
	else if (key == 13)
		k->w = 0;
	else if (key == 123)
		k->left = 0;
	else if (key == 124)
		k->right = 0;
	else if (key == 257)
		k->run = 0;
	else if (key == 53)
		k->esc = 0;
	return (0);
}

void		key_movement(t_game *g)
{
	if (g->key.w)
	{
		if (g->worldmap[(int)(g->ray.posx + g->ray.dirx * g->key.movespeed)]
			[(int)g->ray.posy] == 0)
			g->ray.posx += g->ray.dirx * g->key.movespeed;
		if (g->worldmap[(int)g->ray.posx]
			[(int)(g->ray.posy + g->ray.diry * g->key.movespeed)] == 0)
			g->ray.posy += g->ray.diry * g->key.movespeed;
	}
	if (g->key.s)
	{
		if (g->worldmap[(int)(g->ray.posx - g->ray.dirx * g->key.movespeed)]
			[(int)g->ray.posy] == 0)
			g->ray.posx -= g->ray.dirx * g->key.movespeed;
		if (g->worldmap[(int)g->ray.posx]
			[(int)(g->ray.posy - g->ray.diry * g->key.movespeed)] == 0)
			g->ray.posy -= g->ray.diry * g->key.movespeed;
	}
	key_movement_ad(g);
}

void		key_movement_ad(t_game *g)
{
	t_ray	*r;
	t_keys	*k;

	k = &g->key;
	r = &g->ray;
	if (k->a)
	{
		if (g->worldmap[(int)(r->posx - r->diry * k->movespeed)]
			[(int)r->posy] == 0)
			r->posx -= r->diry * k->movespeed;
		if (g->worldmap[(int)r->posx]
			[(int)(r->posy + r->dirx * k->movespeed)] == 0)
			r->posy += r->dirx * k->movespeed;
	}
	if (k->d)
	{
		if (g->worldmap[(int)(r->posx + r->diry * k->movespeed)]
			[(int)r->posy] == 0)
			r->posx += r->diry * k->movespeed;
		if (g->worldmap[(int)r->posx]
			[(int)(r->posy - r->dirx * k->movespeed)] == 0)
			r->posy -= r->dirx * k->movespeed;
	}
}

void		key_rotation(t_game *g)
{
	t_ray	*r;
	t_keys	*k;

	r = &g->ray;
	k = &g->key;
	if (k->right)
	{
		r->old_dir = r->dirx;
		r->dirx = r->dirx * cos(-k->rots) - r->diry * sin(-k->rots);
		r->diry = r->old_dir * sin(-k->rots) + r->diry * cos(-k->rots);
		r->old_plane = r->planex;
		r->planex = r->planex * cos(-k->rots) - r->planey * sin(-k->rots);
		r->planey = r->old_plane * sin(-k->rots) + r->planey * cos(-k->rots);
	}
	if (k->left)
	{
		r->old_dir = r->dirx;
		r->dirx = r->dirx * cos(k->rots) -
			r->diry * sin(k->rots);
		r->diry = r->old_dir * sin(k->rots) + r->diry * cos(k->rots);
		r->old_plane = r->planex;
		r->planex = r->planex * cos(k->rots) - r->planey * sin(k->rots);
		r->planey = r->old_plane * sin(k->rots) + r->planey * cos(k->rots);
	}
}
