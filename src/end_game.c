/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:52:31 by anschmit          #+#    #+#             */
/*   Updated: 2024/08/01 17:31:22 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map->grid)
		return (-1);
	while (map->grid[i] != NULL)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
	return (-1);
}

void	fight_enemys(t_map *map)
{
	int	i;
	int	j;

	i = map->player_y;
	j = map->player_x;
	if (map->lost < 1)
	{
		if (map->grid[i][j] == 'B')
		{
			ft_printf("you lost!\n");
			map->lost = 1;
		}
	}
}

int	game_won(t_map *map)
{
	if (map->collectibles == 0 && map->won < 1)
	{
		if (map->player_x == map->exit_x && map->player_y == map->exit_y)
		{
			map->won = 1;
			ft_printf("Congratulations! You won the game!\n");
			return (1);
		}
		return (0);
	}
	return (0);
}

void	update_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = map->player_y;
	j = map->player_x;
	if (map->grid[i][j] == 'C')
	{
		map->collectibles--;
		map->grid[i][j] = '0';
	}
}
