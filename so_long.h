/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:47:14 by anschmit          #+#    #+#             */
/*   Updated: 2024/12/02 16:45:26 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# define TILE_SIZE 32

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
	void	*enemy_img;
	int		img_width;
	int		img_height;
	int		won;
	int		lost;
	int		player_moves;
	int		text_height;
	int		text_width;
}	t_map;

int			check_rectangular(t_map *map);
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
int			window(t_map *map);
int			put_image(t_map *map);
int			put_items(t_map *map, char *row, int i);
int			key_hook(int keycode, t_map *map);
void		move_player(int keycode, t_map *map);
void		render_map(t_map *map);
int			free_map(t_map *map);
int			include_count(t_map *map, int position);
int			close_window(t_map *map);
int			game_won(t_map *map);
void		update_collectibles(t_map *map);
void		display_moves(t_map *map);
void		fight_enemys(t_map *map);

#endif
