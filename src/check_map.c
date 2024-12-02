/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:03:48 by anschmit          #+#    #+#             */
/*   Updated: 2024/08/04 14:31:12 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' \
	|| c == 'E' || c == 'C' || c == 'B');
}

int	count_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	map->collectibles = 0;
	while (i < map->height)
	{
		j = 1;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (map->collectibles < 1)
		return (-1);
	return (1);
}

int	count_chars_in_string(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	check_chars(t_map *map)
{
	int	p;
	int	e;
	int	i;
	int	j;

	p = 0;
	e = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		p += (count_chars_in_string(map->grid[i], 'P'));
		e += (count_chars_in_string(map->grid[i], 'E'));
		while (j < map->width)
		{
			if (!is_valid_char(map->grid[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1)
		return (-1);
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while ((map->grid[0][i] != '\0' && map->grid[0][i] != '\n') \
	|| (map->grid[map->height - 1][i] != '\0' \
	&& map->grid[map->height - 1][i] != '\n'))
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (ft_printf("Map is not surrounded by Walls at t/b\n"), -1);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (ft_printf("Map is not surrounded by Walls l/r\n"), -1);
		i++;
	}
	return (1);
}
