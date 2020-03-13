/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:03:55 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/13 16:58:36 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
	int				run;
	int				esc;
	double			movespeed;
	double			rots;
}					t_keys;

typedef struct		s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	int				stepx;
	int				stepy;
	double			perpwalldist;
	int				hit;
	int				side;
	int				lineheight;
	int				texnum;
	int				texx;
	int				texy;
	double			wallx;
	double			step;
	unsigned int	color;
	double			texpos;
	double			old_dir;
	double			old_plane;
	int				textpath;
}					t_ray;

typedef struct		s_texture
{
	int				*texture;
	int				textwidth;
	int				textheight;
	int				byte_per_pixel;
	int				endian;
	int				size_line;
}					t_texture;

typedef struct		s_render
{
	int				drawstart;
	int				drawend;
	int				floor;
	int				sky;
	int				bytes_per_pixel;
	int				size_line;
	int				endian;
	void			*dataimg;
}					t_render;

typedef struct		s_floor
{
	float			raydirx0;
	float			raydiry0;
	float			raydirx1;
	float			raydiry1;
	int				p;
	float			posz;
	float			rowdistance;
	float			floorstepx;
	float			floorstepy;
	float			floorx;
	float			floory;
	int				cellx;
	int				celly;
	int				tx;
	int				ty;
	int				texturefloor;
}					t_floor;

typedef struct		s_spray
{
	float			posx;
	float			posy;
	double			sprayx;
	double			sprayy;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				texx;
	int				texy;
	double			spritedistance;
}					t_spray;

typedef struct		s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				*buff;
	t_keys			key;
	t_render		ren;
	t_ray			ray;
	t_texture		tex[6];
	t_floor			f;
	t_spray			spray[200];
	int				mapwidth;
	int				mapheight;
	char			*spray_path;
	char			*n_path;
	char			*e_path;
	char			*w_path;
	char			*so_path;
	char			*f_path;
	int				f_color;
	int				c_color;
	int				**worldmap;
	char			*texptr;
	double			*zbuffer;
	int				n_spray;
	int				boolean;
	int				maprow;
	int				mapcol;
	char			*map;
	int				on_music;
}					t_game;

/*
** CUB3D.C
*/

int					ft_master(t_game *g);
void				init_data(t_game *g);
void				ft_init_game(char *argv, t_game *g);
void				ft_save_game(char **argv, t_game *g);

/*
** key_manager.c
*/

int					key_pressed(int key, t_keys *k);
int					key_released(int key, t_keys *k);
void				key_movement(t_game *g);
void				key_movement_ad(t_game *g);
void				key_rotation(t_game *g);

/*
** parse_wall.c
*/

int					set_side(t_game *g);
void				get_textures_s_f(t_game *g);
void				get_textures(t_game *g);

/*
** raycasting.c
*/

void				ft_init_var(t_game *g, t_ray *p, int x);
void				ft_rays(t_ray *p);
void				ft_set_hit(t_ray *p, t_game *g, int selector);
void				ft_cal_distance(t_game *g, t_ray *p);
void				ft_raycasting(t_game *g, int selector);

/*
** raycast_aux.c
*/

void				ft_paint_texture(t_game *g, t_ray *p, int x, int y);
void				ft_draw_wall(t_game *g, t_ray *p, int x);
void				ft_set_tex(t_game *g, t_ray *p);
void				spray_paint_aux(t_game *g, int i, int stripe, int y);
void				spray_paint(t_game *g, int i);

/*
** raycast_f_s.c
*/

void				floor_painting(t_game *g, int i);
void				floor_raycasting(t_game *g);
void				shortsprites(t_game *g);
void				init_spray(t_game *g, int i);
void				spray_raycasting(t_game *g);

/*
** read_map.c
*/

void				ft_path_s(char *line, t_game *g);
void				ft_path_f(char *line, t_game *g);
void				ft_path_c(char *line, t_game *g);
void				ft_path_color(char *line, t_game *g);
void				ft_check_line(int fd, t_game *g);

/*
** read_map2.c
*/

int					ft_closemap(t_game *g, unsigned int x, unsigned int y);
void				ft_check_error(t_game *g);
char				*ft_map2(int x, char *map, t_game *g);
void				ft_read_map(char *file, t_game *g);
int					ft_map_read(char *line, t_game *g);

/*
** read_map3.c
*/

void				ft_isspray(t_game *g, int x, int y);
void				ft_screensize(t_game *g, char *line);
void				ft_path_new_aux(char *line, t_game *g);
void				ft_path_new(char *line, t_game *g);
void				ft_map(char *map, t_game *g, int row);

/*
** save.c
*/

void				int_to_char(unsigned char *c, int i);
int					bmp_header(int fd, t_game *g, int padsize);
int					bmp_data(int fd, t_game *g, int padsize);
int					take_screenshot(t_game *g);
void				check_screenshot(t_game *g, char *argv);

/*
** utils.c
*/

int					deal_key(t_game *g);
void				ft_error(char *s, t_game *g);
int					close_game(t_game *g);
void				ft_set_start(int x, int y, char *map, t_game *g);

#endif
