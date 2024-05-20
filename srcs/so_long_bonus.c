/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:51:15 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/20 16:15:47 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initial_enemy(t_maps *map, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	map->random = (t_pos *)calloc(count, sizeof(t_pos));
	if (!map->random)
		errors("error occurred in calloc in initial_enemy()", map);
	while (map->map[i][j] && i <= map->height && tmp <= count)
	{
		while (map->map[i][j] && j <= map->width && tmp <= count)
		{
			if (map->map[i][j] == 'X')
			{
				map->enemy[tmp] = (t_pos){i, j};
				tmp++;
			}
			j++;
		}
		i++;
	}
}

void	initialize(t_maps *map, t_count *num)
{
	map->width = 0;
	map->height = 0;
	map->map_oneline = NULL;
	map->map = NULL;
	map->maptmp = NULL;
	map->fps = 0;
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
	initial_enemy(&map, map.enemy_count);
	mlx_loop_hook(map.mlx, &move_enemy, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_every(&map);
	return (0);
}
