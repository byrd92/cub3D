/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:03:33 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/13 17:02:40 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_master(t_game *g)
{
	deal_key(g);
	ft_raycasting(g, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->ren.dataimg, 0, 0);
	return (1);
}

void	init_data(t_game *g)
{
	ft_bzero(g, sizeof(t_game));
	ft_bzero(&g->key, sizeof(t_keys));
	g->key.movespeed = 0.1;
	g->key.rots = 0.05;
}

void	ft_init_game(char *argv, t_game *g)
{
	ft_read_map(argv, g);
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->mapwidth, g->mapheight, "cub3d");
	g->ren.dataimg = mlx_new_image(g->mlx_ptr, g->mapwidth, g->mapheight);
	get_textures(g);
	g->buff = (int *)mlx_get_data_addr(g->ren.dataimg, &g->ren.bytes_per_pixel,
				&g->ren.size_line, &g->ren.endian);
	system("afplay music/music1.mp3 &");
	g->on_music = 1;
	mlx_hook(g->win_ptr, 2, 1, key_pressed, &g->key);
	mlx_hook(g->win_ptr, 3, 1, key_released, &g->key);
	mlx_hook(g->win_ptr, 17, 1, close_game, (void *)g);
	mlx_loop_hook(g->mlx_ptr, ft_master, g);
	mlx_loop(g->mlx_ptr);
}

void	ft_save_game(char **argv, t_game *g)
{
	ft_read_map(argv[1], g);
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->mapwidth, g->mapheight, "cub3d");
	g->ren.dataimg = mlx_new_image(g->mlx_ptr, g->mapwidth, g->mapheight);
	get_textures(g);
	g->buff = (int *)mlx_get_data_addr(g->ren.dataimg, &g->ren.bytes_per_pixel,
				&g->ren.size_line, &g->ren.endian);
	check_screenshot(g, argv[2]);
}

int		main(int argc, char **argv)
{
	t_game g;

	init_data(&g);
	if (argc == 2)
		ft_init_game(argv[1], &g);
	else if (argc == 3)
		ft_save_game(argv, &g);
	else
		ft_error("ERROR, NUMBER OF ARGUMENTS INVALID\n", &g);
	return (0);
}
