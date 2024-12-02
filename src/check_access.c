/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:01:53 by anschmit          #+#    #+#             */
/*   Updated: 2024/08/04 14:23:14 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**create_map_copy(t_map *map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * map->height);
	if (!copy)
		return (NULL);
	while (i < map->height)
	{
		copy[i] = strdup(map->grid[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[i--]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

int	check_path(t_map *map)
{
	char	**map_copy;
	int		i;

	map->flood_collect = 0;
	map->flood_exit = 0;
	set_positions(map);
	map_copy = create_map_copy(map);
	i = 0;
	if (!map_copy)
		return (-1);
	flood_fill(map, map_copy, map->player_x, map->player_y);
	while (i < map->height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (map->flood_collect != map->collectibles || map->flood_exit != 1)
		return (-1);
	return (1);
}

void	flood_fill(t_map *map, char **map_copy, int x, int y)
{
	if (y < 1 || y > map->height || x < 1 || x > map->width \
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		map->flood_collect += 1;
	if (map_copy[y][x] == 'E')
		map->flood_exit += 1;
	map_copy[y][x] = 'V';
	flood_fill(map, map_copy, x + 1, y);
	flood_fill(map, map_copy, x - 1, y);
	flood_fill(map, map_copy, x, y + 1);
	flood_fill(map, map_copy, x, y - 1);
}
