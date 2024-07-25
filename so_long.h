/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:47:14 by anschmit          #+#    #+#             */
/*   Updated: 2024/07/24 11:34:46 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <math.h>
# include "/home/anschmit/done/libft/includes/libft.h"
# include "/home/anschmit/done/libft/includes/get_next_line.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
	int		flood_collect;
	int		flood_exit;
	void	*mlx;
	void	*window;
	void	*player_img;
	void	*wall_img;
	void	*collectibles_img;
	void	*exit_img;
	void	*floor_img;
	int		img_width;
	int		img_height;
	int		moves;

} t_map;

int			check_rectangular(t_map *map);
int			add_line_to_map(t_map *map, char *line);
int			parse_map(const char *filename, t_map *map);
int			initialize_map(char *filename, t_map *map);
int			validate_map(char *filename, t_map *map);
int			check_path(t_map *map);
void		flood_fill(t_map *map, char **map_copy, int x, int y);
int			is_valid_char(char c);
int			count_collectibles(t_map *map);
int			count_chars_in_string(const char *str, char c);
int			check_chars(t_map *map);
int			check_walls(t_map *map);
void		set_positions(t_map *map);
int			load_textures(t_map *map);

#endif
