/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:44:45 by anschmit          #+#    #+#             */
/*   Updated: 2024/08/04 13:27:06 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_textures(t_map *map)
{
	map->player_img = mlx_xpm_file_to_image(map->mlx, "./assets/player.xpm", \
	&map->img_width, &map->img_height);
	map->wall_img = mlx_xpm_file_to_image(map->mlx, "./assets/wall.xpm", \
	&map->img_width, &map->img_height);
	map->collectibles_img = mlx_xpm_file_to_image(map->mlx, \
	"./assets/collectibles.xpm", &map->img_width, &map->img_height);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, "./assets/floor.xpm", \
	&map->img_width, &map->img_width);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, "./assets/exit.xpm", \
	&map->img_width, &map->img_height);
	map->enemy_img = mlx_xpm_file_to_image(map->mlx, "./assets/bomb.xpm", \
	&map->img_width, &map->img_height);
	if (!map->player_img || !map->wall_img || !map->collectibles_img || \
	!map->floor_img || !map->exit_img || !map->enemy_img)
		return (ft_printf("Failed to load textures!"), -1);
	return (1);
}

int	put_image(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i] != NULL)
	{
		put_items(map, map->grid[i], i);
		i++;
	}
	if (i > map->height)
		return (-1);
	if (map->won != 1 && map->lost != 1)
		display_moves(map);
	if (map->won == 1)
	{
		mlx_string_put(map->mlx, map->window, map->text_width, \
		map->text_height, 0xFF69B4, "Congrats! You won!");
	}
	if (map->lost == 1)
	{
		mlx_string_put(map->mlx, map->window, map->text_width, \
		map->text_height, 0xFF69B4, "you lost! :(");
	}
	return (0);
}

int	put_items(t_map *map, char *row, int i)
{
	int	j;

	j = 0;
	while (row[j] != '\n' && row[j] != '\0')
	{
		if (row[j] == '1')
			mlx_put_image_to_window(map->mlx, map->window, map->wall_img, \
			j * TILE_SIZE, i * TILE_SIZE);
		if (row[j] == 'C')
			mlx_put_image_to_window(map->mlx, map->window, \
			map->collectibles_img, j * TILE_SIZE, i * TILE_SIZE);
		if (row[j] == 'E' && map->collectibles == 0)
			mlx_put_image_to_window(map->mlx, map->window, map->exit_img, \
			j * TILE_SIZE, i * TILE_SIZE);
		if (row[j] == '0')
			mlx_put_image_to_window(map->mlx, map->window, map->floor_img, \
			j * TILE_SIZE, i * TILE_SIZE);
		if (row[j] == 'B')
			mlx_put_image_to_window(map->mlx, map->window, map->enemy_img, \
			j * TILE_SIZE, i * TILE_SIZE);
		j++;
		mlx_put_image_to_window(map->mlx, map->window, map->player_img, \
		map->player_x * TILE_SIZE, map->player_y * TILE_SIZE);
	}
	return (0);
}

int	close_window(t_map *map)
{
	mlx_destroy_image(map->mlx, map->player_img);
	mlx_destroy_image(map->mlx, map->wall_img);
	mlx_destroy_image(map->mlx, map->floor_img);
	mlx_destroy_image(map->mlx, map->exit_img);
	mlx_destroy_image(map->mlx, map->collectibles_img);
	mlx_destroy_image(map->mlx, map->enemy_img);
	mlx_destroy_window(map->mlx, map->window);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	exit(0);
}

int	window(t_map *map)
{
	int	height;
	int	width;

	height = (map->height + 1) * TILE_SIZE;
	width = map->width * TILE_SIZE;
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		return (ft_printf("Error! MLX initialization failed!"), -1);
	map->window = mlx_new_window(map->mlx, width, height, "so_long");
	if (map->window == NULL)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		return (1);
	}
	if (load_textures(map) == -1 || put_image(map) == -1)
		return (ft_printf("Error! Problem with the images!\n", 1));
	mlx_key_hook(map->window, key_hook, map);
	mlx_hook(map->window, 17, 0, &close_window, map);
	mlx_loop(map->mlx);
	return (0);
}
