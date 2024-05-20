/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:55:56 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/20 16:22:19 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	encount_enemy(t_maps *map)
{
	int	i;

	i = 0;
	while (i < map->enemy_count)
	{
		if ((map->player.j * PIXEL == map->img[ENM_B]->instances[i].x \
		&& map->player.i * PIXEL == map->img[ENM_B]->instances[i].y) \
		|| (map->player.j * PIXEL == map->img[ENM_F]->instances[i].x \
		&& map->player.i * PIXEL == map->img[ENM_F]->instances[i].y) \
		|| (map->player.j * PIXEL == map->img[ENM_L]->instances[i].x \
		&& map->player.i * PIXEL == map->img[ENM_L]->instances[i].y) \
		|| (map->player.j * PIXEL == map->img[ENM_R]->instances[i].x \
		&& map->player.i * PIXEL == map->img[ENM_R]->instances[i].y))
		{
			img_onoff(map, map->ply_nowimg, false);
			img_onoff(map, PLY_FAIL, true);
			map->status = LOST;
			mlx_key_hook(map->mlx, ending_prints, map);
		}
		i++;
	}
}

void	enemy_img_direction(t_maps *map, int count, t_direct i)
{
	disable_enemy(map, count);
	if (i == UP)
		map->img[ENM_B]->instances[count].enabled = true;
	if (i == DOWN)
		map->img[ENM_F]->instances[count].enabled = true;
	if (i == LEFT)
		map->img[ENM_L]->instances[count].enabled = true;
	if (i == RIGHT)
		map->img[ENM_R]->instances[count].enabled = true;
}

void	enemy_generator(t_maps *map, int count)
{
	map->random[count].i = (rand() % 4) - 2;
	map->random[count].j = 0;
	if (map->random[count].i == 0)
		map->random[count].j = (rand() % 7) - 3;
	if (map->random[count].i < 0)
		enemy_img_direction(map, count, UP);
	else if (map->random[count].i > 0)
		enemy_img_direction(map, count, DOWN);
	if (map->random[count].j < 0)
		enemy_img_direction(map, count, LEFT);
	else if (map->random[count].j > 0)
		enemy_img_direction(map, count, RIGHT);
}
