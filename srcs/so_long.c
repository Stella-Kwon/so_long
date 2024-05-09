/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:51:15 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/08 18:33:36 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialize(t_maps *map, t_count *num)
{
	map->width = 0;
	map->height = 0;
	map->map_oneline = NULL;
	map->map = NULL;
	map->maptmp = NULL;
	map->moveprint = NULL;
	map->collect_count = 0;
	map->collectives = 0;
	map->moves = 0;
	map->texture = NULL;
	map->mlx = NULL;
	num->collectives = 0;
	num->player = 0;
	num->exit = 0;
	num->enemies = 0;
	num->i = 0;
	num->j = 0;
}

// void keyhook(mlx_key_data_t keydata, void* param)
// {
// 	// t_maps *map;

// 	// map = (t_maps *)param;
// 	(void)param;
// 	// If we PRESS the 'J' key, print "Hello".
// 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// 		puts("Hello ");

// 	// If we RELEASE the 'K' key, print "World".
// 	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
// 		puts("World");

// 	// If we HOLD the 'L' key, print "!".
// 	if (keydata.key == MLX_KEY_L && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
// 		puts("!");
// }


int	main(int argc, char **argv)
{
	t_maps	map;
	t_count	num;

	initialize(&map, &num);
	if (argc != 2)
		errors("No map", &map);
	check_file_extension(argv[1], &map);
	read_map(argv[1], &map);
	check_rectangular(&map);
	check_wall(&map);
	check_instance_count(&map, &num);
	check_position(&map, &num);
	generate_imgs(&map);
	img_to_window(&map, &num);
	mlx_key_hook(map.mlx, player_keyhook, &map);
	// // mlx_loop_hook(map.mlx, move_enemy, &map); // 
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_every(&map);
	return (0);
}
