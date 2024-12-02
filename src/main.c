/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:11 by anschmit          #+#    #+#             */
/*   Updated: 2024/08/01 17:29:37 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_game(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->collectibles = 0;
	map->flood_collect = 0;
	map->flood_exit = 0;
	map->mlx = NULL;
	map->window = NULL;
	map->player_img = NULL;
	map->wall_img = NULL;
	map->collectibles_img = NULL;
	map->exit_img = NULL;
	map->floor_img = NULL;
	map->enemy_img = NULL;
	map->img_width = 32;
	map->img_height = 32;
	map->player_moves = 0;
	map->won = 0;
	map->lost = 0;
	map->text_height = 0;
	map->text_width = 0;
}

int	main(int argc, char **argv)
{
	t_map	new_map;

	if (argc != 2)
	{
		ft_printf("Error! Invalid numbers of Arguments. Try again.");
		return (1);
	}
	initialize_game(&new_map);
	if (validate_map(argv[1], &new_map) == -1)
		return (ft_printf("Error! Map is invalid!\n"), 1);
	else
		window(&new_map);
	return (0);
}
