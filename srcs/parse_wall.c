/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:52:59 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/09 16:37:31 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			set_side(t_game *g)
{
	if (g->ray.posx > (double)g->ray.mapx)
	{
		if (g->ray.side == 1 && g->ray.posy > g->ray.mapy)
			return (2);
		else if (g->ray.side == 1 && g->ray.posy < g->ray.mapy)
			return (3);
		else
			return (0);
	}
	else
	{
		if (g->ray.side == 1 && g->ray.posy > g->ray.mapy)
			return (2);
		else if (g->ray.side == 1 && g->ray.posy < g->ray.mapy)
			return (3);
		else
			return (1);
	}
}

void		get_textures_s_f(t_game *g)
{
	if (g->f_path != NULL && g->f.texturefloor == 1)
	{
		g->texptr = mlx_xpm_file_to_image(g->mlx_ptr, g->f_path,
		&g->tex[4].textwidth, &g->tex[4].textheight);
		g->tex[4].texture = (int *)mlx_get_data_addr(g->texptr,
		&g->tex[4].byte_per_pixel, &g->tex[4].size_line, &g->tex[4].endian);
	}
	if (g->spray_path != NULL)
	{
		g->texptr = mlx_xpm_file_to_image(g->mlx_ptr, g->spray_path,
		&g->tex[5].textwidth, &g->tex[5].textheight);
		g->tex[5].texture = (int *)mlx_get_data_addr(g->texptr,
		&g->tex[5].byte_per_pixel, &g->tex[5].size_line, &g->tex[5].endian);
	}
}

void		get_textures(t_game *g)
{
	if (!(g->texptr = mlx_xpm_file_to_image(g->mlx_ptr, g->n_path,
	&g->tex[0].textwidth, &g->tex[0].textheight)))
		ft_error("ERROR, N_PATH WRONG", g);
	g->tex[0].texture = (int *)mlx_get_data_addr(g->texptr,
	&g->tex[0].byte_per_pixel, &g->tex[0].size_line, &g->tex[0].endian);
	if (!(g->texptr = mlx_xpm_file_to_image(g->mlx_ptr, g->so_path,
	&g->tex[1].textwidth, &g->tex[1].textheight)))
		ft_error("ERROR, SO_PATH WRONG", g);
	g->tex[1].texture = (int *)mlx_get_data_addr(g->texptr,
	&g->tex[1].byte_per_pixel, &g->tex[1].size_line, &g->tex[1].endian);
	if (!(g->texptr = mlx_xpm_file_to_image(g->mlx_ptr, g->w_path,
	&g->tex[2].textwidth, &g->tex[2].textheight)))
		ft_error("ERROR, W_PATH WRONG", g);
	g->tex[2].texture = (int *)mlx_get_data_addr(g->texptr,
		&g->tex[2].byte_per_pixel, &g->tex[2].size_line, &g->tex[2].endian);
	if (!(g->texptr = mlx_xpm_file_to_image(g->mlx_ptr,
	g->e_path, &g->tex[3].textwidth, &g->tex[3].textheight)))
		ft_error("ERROR, W_PATH WRONG", g);
	g->tex[3].texture = (int *)mlx_get_data_addr(g->texptr,
		&g->tex[3].byte_per_pixel, &g->tex[3].size_line, &g->tex[3].endian);
	get_textures_s_f(g);
}
