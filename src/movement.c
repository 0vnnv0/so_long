/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:28:43 by anschmit          #+#    #+#             */
/*   Updated: 2024/08/01 17:33:10 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(int keycode, t_map *map)
{
	int	i;
	int	j;

	i = map->player_y;
	j = map->player_x;
	if (map->won < 1 && map->lost < 1)
	{
		if (keycode == XK_Left && include_count(map, map->grid[i][j - 1]))
			map->player_x--;
		if (keycode == XK_Right && include_count(map, map->grid[i][j + 1]))
			map->player_x++;
		if (keycode == XK_Up && include_count(map, map->grid[i - 1][j]))
			map->player_y--;
		if (keycode == XK_Down && include_count(map, map->grid[i + 1][j]))
			map->player_y++;
		fight_enemys(map);
		game_won(map);
		render_map(map);
	}
}

int	include_count(t_map *map, int position)
{
	if (position != '1' && map->won != 1)
	{
		map->player_moves++;
		render_map(map);
		return (1);
	}
	return (0);
}

void	display_moves(t_map *map)
{
	char	*move_str;

	map->text_width = 10;
	map->text_height = map->height * TILE_SIZE + 16;
	move_str = ft_itoa(map->player_moves);
	mlx_string_put(map->mlx, map->window, map->text_width, map->text_height, \
	0xFF69B4, "Moves:");
	mlx_string_put(map->mlx, map->window, map->text_width + 70, \
	map->text_height, 0xFFC0CB, move_str);
	free(move_str);
}

void	render_map(t_map *map)
{
	mlx_clear_window(map->mlx, map->window);
	put_image(map);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == XK_Escape)
	{
		close_window(map);
		map->window = NULL;
		exit (0);
	}
	if (keycode == XK_Left || keycode == XK_Right \
			|| keycode == XK_Up || keycode == XK_Down)
		move_player(keycode, map);
	update_collectibles(map);
	render_map(map);
	return (0);
}
