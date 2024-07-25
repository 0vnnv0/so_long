/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:11 by anschmit          #+#    #+#             */
/*   Updated: 2024/07/25 12:27:16 by anschmit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_textures(t_map *map)
{

	map->player_img = mlx_xpm_file_to_image(map->mlx, "./assets/player.xbm", &map->img_width, &map->img_height);
	map->wall_img = mlx_xpm_file_to_image(map->mlx, "./assets/wall.xbm", &map->img_width, &map->img_height);
	map->collectibles_img = mlx_xpm_file_to_image(map->mlx, "./assets/collectibles.xbm", &map->img_width, &map->img_height);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, "./assets/floor.xbm", &map->img_width, &map->img_width);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, "./assets/exit.xbm", &map->img_width, &map->img_height);
	if(!map->player_img || !map->wall_img || !map->collectibles_img || !map->floor_img || !map->exit_img)
		return(perror("Failed to load textures!"), -1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map new_map;

	if (argc != 2)
	{
		ft_printf("Error! Invalid numbers of Arguments. Try again.");
		return (1);
	}
	if(validate_map(argv[1], &new_map) == -1)
		return(ft_printf("Error! Map is invalid!\n"), 1);
	new_map.mlx = mlx_init();
	if (new_map.mlx == NULL)
	{
		return(ft_printf("Error! MLX initialization failed!"), 1);
	}
	new_map.window = mlx_new_window(new_map.mlx, 600, 400, "so_long");
	if (new_map.window == NULL)
	{
		mlx_destroy_display(new_map.mlx);
		free(new_map.mlx);
		return (1);
	}
	return (0);
}
