/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:25:24 by anschmit          #+#    #+#             */
/*   Updated: 2024/08/04 14:24:56 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_rectangular(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (map->grid[0][len] != '\n' && map->grid[0][len] != '\0')
		len++;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] != '\n' && map->grid[i][j] != '\0')
			j++;
		if (j != len)
			return (-1);
		i++;
	}
	return (1);
}

int	parse_map(const char *filename, t_map *map)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	i = 0;
	if (fd < 0)
		return (-1);
	while (i < map->height)
	{
		map->grid[i] = get_next_line(fd);
		if (!map->grid[i])
		{
			close (fd);
			return (-1);
		}
		i++;
	}
	map->grid[i] = NULL;
	map->grid[i + 1] = NULL;
	close(fd);
	return (1);
}

int	initialize_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	map->height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Could not open file %s\n"), -1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	while (line != NULL)
	{
		if (map->height == 0)
			map->width = ft_strlen(line) - 1;
		map->height += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	validate_map(char *filename, t_map *map)
{
	if (initialize_map(filename, map) == -1)
		return (ft_printf("Error! No map found!\n"), -1);
	map->grid = malloc(sizeof(char *) * (map->height + 2));
	if (!map->grid)
		return (ft_printf("Error! Memory allocation failed!"), -1);
	if (parse_map(filename, map) == -1)
		return (ft_printf("Error! Invalid map! \n"), -1);
	if (check_rectangular(map) == -1)
		return (ft_printf("Error: Map is not rectangular!\n"), -1);
	if (check_chars(map) == -1)
		return (ft_printf("Error: wrong char or E or P missing!\n"), -1);
	if (count_collectibles(map) <= 0)
		return (ft_printf("Error: not enough or too many!\n"), -1);
	if (check_walls(map) == -1)
		return (ft_printf("Error: problem with the walls!\n"), -1);
	if (check_path(map) == -1)
		return (ft_printf("Error: Player can't move correctly\n"), -1);
	return (1);
}
