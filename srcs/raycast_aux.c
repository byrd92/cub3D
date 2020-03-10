/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:44:06 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/10 17:44:13 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_paint_texture(t_game *g, t_ray *p, int x, int y)
{
	p->texy = (int)p->texpos & (g->tex[p->textpath].textheight - 1);
	p->texpos += p->step;
	p->color = g->tex[p->textpath].texture[g->tex[p->textpath].
			textheight * p->texy + p->texx];
	if (p->side == 1)
		p->color = (p->color >> 1) & 8355711;
	g->buff[(y * g->mapwidth + x)] = p->color;
}

void		ft_draw_wall(t_game *g, t_ray *p, int x)
{
	int y;

	y = 0;
	y = 0;
	while (++y < g->mapheight - 1)
	{
		if (y < g->ren.drawstart)
			g->buff[(y * g->mapwidth) + x] = g->c_color;
		else if (y >= g->ren.drawstart && y <= g->ren.drawend)
		{
			p->texy = (int)p->texpos & (g->tex[p->textpath].textheight - 1);
			p->texpos += p->step;
			p->color = g->tex[p->textpath].texture
			[g->tex[p->textpath].textheight * p->texy + p->texx];
			if (p->side == 1)
				p->color = (p->color >> 1) & 8355711;
			g->buff[(y * g->mapwidth + x)] = p->color;
		}
		else if (y > g->ren.drawend && g->f.texturefloor == 0)
			g->buff[(y * g->mapwidth) + x] = g->f_color;
	}
}

void		ft_set_tex(t_game *g, t_ray *p)
{
	p->texx = (int)(p->wallx * (double)g->tex[p->textpath].textwidth);
	if (p->side == 0 && p->raydirx > 0)
		p->texx = g->tex[p->textpath].textwidth - p->texx - 1;
	if (p->side == 1 && p->raydiry < 0)
		p->texx = g->tex[p->textpath].textwidth - p->texx - 1;
	p->step = 1.0 * g->tex[p->textpath].textwidth / p->lineheight;
	p->texpos = (g->ren.drawstart - g->mapheight
	/ 2 + p->lineheight / 2) * p->step;
}

void		spray_paint_aux(t_game *g, int i, int stripe, int y)
{
	int d;
	int color;

	while (y++ < g->spray[i].drawendy)
	{
		d = y * 256 - g->mapheight * 128 +
		g->spray[i].spriteheight * 128;
		g->spray[i].texy = ((d * g->tex[5].textheight) /
		g->spray[i].spriteheight) / 256;
		color = g->tex[5].texture[g->tex[5].textwidth *
		g->spray[i].texy + g->spray[i].texx];
		if (color != 0)
			g->buff[(y * g->mapwidth + stripe)] = color;
	}
}

void		spray_paint(t_game *g, int i)
{
	int stripe;
	int y;

	stripe = g->spray[i].drawstartx;
	while (stripe < g->spray[i].drawendx)
	{
		g->spray[i].texx = (int)((256 * (stripe - (-g->spray[i].spritewidth /
		2 + g->spray[i].spritescreenx)) * g->tex[5].textwidth /
		g->spray[i].spritewidth) / 256);
		y = g->spray[i].drawstarty;
		if (g->spray[i].transformy > 0 && stripe > 0 && stripe < g->mapwidth
		&& g->spray[i].transformy < g->zbuffer[stripe])
			spray_paint_aux(g, i, stripe, y);
		stripe++;
	}
}
