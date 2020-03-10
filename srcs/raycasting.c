/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:44:03 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/09 17:20:23 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_init_var(t_game *g, t_ray *p, int x)
{
	p->textpath = set_side(g);
	p->camerax = 2 * x / (double)g->mapwidth - 1;
	p->raydirx = p->dirx + p->planex * p->camerax;
	p->raydiry = p->diry + p->planey * p->camerax;
	p->mapx = (int)p->posx;
	p->mapy = (int)p->posy;
	p->deltadistx = fabs(1 / p->raydirx);
	p->deltadisty = fabs(1 / p->raydiry);
	p->hit = 0;
	g->boolean = 0;
}

void		ft_rays(t_ray *p)
{
	if (p->raydirx < 0)
	{
		p->stepx = -1;
		p->sidedistx = (p->posx - p->mapx) * p->deltadistx;
	}
	else
	{
		p->stepx = 1;
		p->sidedistx = (p->mapx + 1.0 - p->posx) * p->deltadistx;
	}
	if (p->raydiry < 0)
	{
		p->stepy = -1;
		p->sidedisty = (p->posy - p->mapy) * p->deltadisty;
	}
	else
	{
		p->stepy = 1;
		p->sidedisty = (p->mapy + 1.0 - p->posy) * p->deltadisty;
	}
}

void		ft_set_hit(t_ray *p, t_game *g, int selector)
{
	while (p->hit == 0)
	{
		if (p->sidedistx < p->sidedisty)
		{
			p->sidedistx += p->deltadistx;
			p->mapx += p->stepx;
			p->side = 0;
		}
		else
		{
			p->sidedisty += p->deltadisty;
			p->mapy += p->stepy;
			p->side = 1;
		}
		if (g->worldmap[p->mapx][p->mapy] == 2 && selector == 1)
			g->boolean = 1;
		if (g->worldmap[p->mapx][p->mapy] == 1)
			p->hit = 1;
	}
}

void		ft_cal_distance(t_game *g, t_ray *p)
{
	if (p->side == 0)
		p->perpwalldist = (p->mapx - p->posx + (1 - p->stepx) / 2) / p->raydirx;
	else
		p->perpwalldist = (p->mapy - p->posy + (1 - p->stepy) / 2) / p->raydiry;
	p->lineheight = (int)(g->mapheight / p->perpwalldist);
	g->ren.drawstart = -p->lineheight / 2 + g->mapheight / 2;
	if (g->ren.drawstart < 0)
		g->ren.drawstart = 0;
	g->ren.drawend = p->lineheight / 2 + g->mapheight / 2;
	if (g->ren.drawend >= (int)g->mapheight)
		g->ren.drawend = g->mapheight - 1;
	p->texnum = g->worldmap[p->mapx][p->mapy] - 1;
	if (p->side == 0)
		p->wallx = p->posy + p->perpwalldist * p->raydiry;
	else
		p->wallx = p->posx + p->perpwalldist * p->raydirx;
	p->wallx -= floor((p->wallx));
}

void		ft_raycasting(t_game *g, int selector)
{
	int		x;
	t_ray	*p;

	p = &g->ray;
	if (g->f.texturefloor == 1 && selector == 0)
		floor_raycasting(g);
	x = 0;
	while (x++ < g->mapwidth)
	{
		ft_init_var(g, p, x);
		ft_rays(p);
		ft_set_hit(p, g, selector);
		if (g->boolean == 1 && selector == 1)
			continue;
		ft_cal_distance(g, p);
		ft_set_tex(g, p);
		ft_draw_wall(g, p, x);
		g->zbuffer[x] = p->perpwalldist;
	}
	if (selector == 0)
	{
		shortsprites(g);
		spray_raycasting(g);
		ft_raycasting(g, 1);
	}
}
