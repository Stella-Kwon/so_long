/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:51:15 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/15 16:02:31 by skwon2           ###   ########.fr       */
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
	map->enemy_count = 0;
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
	initial_enemy(&map, &map.random, map.enemy_count);
	printf("random->i[0]: %d\n",map.random.i[0]);
	mlx_loop_hook(map.mlx, &move_enemy, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_every(&map);
	return (0);
}
