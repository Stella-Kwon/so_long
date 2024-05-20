/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_loophook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:47 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/20 16:38:48 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_enemy_to_direction(t_maps *map, int count)
{
	map->img[ENM_B]->instances[count].x = map->enemy[count].j * PIXEL;
	map->img[ENM_B]->instances[count].y = map->enemy[count].i * PIXEL;
	map->img[ENM_F]->instances[count].x = map->enemy[count].j * PIXEL;
	map->img[ENM_F]->instances[count].y = map->enemy[count].i * PIXEL;
	map->img[ENM_L]->instances[count].x = map->enemy[count].j * PIXEL;
	map->img[ENM_L]->instances[count].y = map->enemy[count].i * PIXEL;
	map->img[ENM_R]->instances[count].x = map->enemy[count].j * PIXEL;
	map->img[ENM_R]->instances[count].y = map->enemy[count].i * PIXEL;
}

void	check_right_spot(t_maps *map, int count, int i)
{
	the_next(map, map->enemy[count], i);
	if (map->map[map->next.i][map->next.j] != '1' && \
	(map->map[map->next.i][map->next.j] != 'E'))
	{
		if (i == UP)
			map->enemy[count].i--;
		if (i == DOWN)
			map->enemy[count].i++;
		if (i == LEFT)
			map->enemy[count].j--;
		if (i == RIGHT)
			map->enemy[count].j++;
		move_enemy_to_direction(map, count);
		if (map->collect_count == map->collectives)
		{
			img_onoff(map, EXIT_CLOSE, false);
			img_onoff(map, EXIT_OPEN, true);
		}
	}
}

void	move_img_x(t_maps *map, int count)
{
	while (map->random[count].j < 0)
	{
		check_right_spot(map, count, LEFT);
		map->random[count].j++;
	}
	while (map->random[count].j > 0)
	{
		check_right_spot(map, count, RIGHT);
		map->random[count].j--;
	}
}

void	move_img_y(t_maps *map, int count)
{
	while (map->random[count].i < 0)
	{
		check_right_spot(map, count, UP);
		map->random[count].i++;
	}
	while (map->random[count].i > 0)
	{
		check_right_spot(map, count, DOWN);
		map->random[count].i--;
	}
}

void	move_enemy(void *param)
{
	t_maps	*map;
	int		count;

	map = (t_maps *)param;
	count = 0;
	encount_enemy(map);
	if (map->fps++ < 50)
		return ;
	while (count < map->enemy_count)
	{
		enemy_generator(map, count);
		count++;
	}
	count = 0;
	while (count < map->enemy_count && map->status == PLAYING)
	{
		move_img_x(map, count);
		move_img_y(map, count);
		count++;
	}
	map->fps = 0;
}
