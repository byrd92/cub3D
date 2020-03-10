/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <egarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:22:08 by egarcia-          #+#    #+#             */
/*   Updated: 2020/03/10 18:38:41 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_path_s(char *line, t_game *g)
{
	int i;

	i = 0;
	if (line[1] == 'O')
	{
		while (line[i] != '.')
			i++;
		g->so_path = ft_strdup(&line[i]);
	}
	else if (line[1] == ' ')
	{
		while (line[i] != '.')
			i++;
		g->spray_path = ft_strdup(&line[i]);
	}
}

void		ft_path_f(char *line, t_game *g)
{
	int r;
	int gr;
	int b;
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	gr = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	b = ft_atoi(&line[i]);
	if ((r < 0 || r > 255) || (gr < 0 || gr > 255) || (b < 0 || b > 255))
		ft_error("Error\n Color out of RGB", g);
	if (g->f_color == 0)
		g->f_color = r * 65536 + gr * 256 + b;
	else
		ft_error("Error\n path F duplicated", g);
}

void		ft_path_c(char *line, t_game *g)
{
	int r;
	int gr;
	int b;
	int i;

	i = 1;
	i++;
	while (line[i] == ' ')
		i++;
	r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	gr = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	b = ft_atoi(&line[i]);
	if ((r < 0 || r > 255) || (gr < 0 || gr > 255) || (b < 0 || b > 255))
		ft_error("Error\n Color out of RGB", g);
	if (g->c_color == 0)
		g->c_color = r * 65536 + gr * 256 + b;
	else
		ft_error("Error\n path C duplicated", g);
}

void		ft_path_color(char *line, t_game *g)
{
	if (line[0] == 'F' && line[1] != 'T')
		ft_path_f(line, g);
	else if (line[0] == 'C')
		ft_path_c(line, g);
}

void		ft_check_line(int fd, t_game *g)
{
	int		ret;
	char	*line;
	int		mapread;

	ret = 1;
	g->map = ft_strdup("");
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line[0] == 'R')
			ft_screensize(g, line);
		else if (line[0] == 'S')
			ft_path_s(line, g);
		else if (line[0] == 'N' || line[0] == 'W' ||
			line[0] == 'E' || (line[0] == 'F' && line[1] == 'T'))
			ft_path_new(line, g);
		else if (line[0] == 'F' || line[0] == 'C')
			ft_path_color(line, g);
		else if (ft_isdigit(line[0]) || line[0] == ' ')
			mapread = ft_map_read(line, g);
		else if (mapread == 1 && *line != '\0')
			ft_error("Error \n Map incorret or items after map.", g);
		free(line);
		line = NULL;
	}
}
