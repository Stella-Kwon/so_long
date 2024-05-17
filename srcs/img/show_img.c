/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:01:28 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/16 10:42:58 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	player_img(t_maps *map, t_count *num)
{
	if (mlx_image_to_window(map->mlx, map->img[PLY_START],\
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Player_start img to window failed", map);
	if (mlx_image_to_window(map->mlx, map->img[PLY_R], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Player_right img to window failed", map);
	if (mlx_image_to_window(map->mlx, map->img[PLY_L], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Player_left img to window failed", map);
	if (mlx_image_to_window(map->mlx, map->img[PLY_F], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Player_front img to window failed", map);
	if (mlx_image_to_window(map->mlx, map->img[PLY_B], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Player_back img to window failed", map);
}

static void	wall_collectives(t_maps *map, t_count *num)
{
	if (map->map[num->i][num->j] == 'C')
	{
		if (mlx_image_to_window(map->mlx, map->img[COLLECTIVE], \
	num->j * PIXEL, num->i * PIXEL) < 0)
			errors("Collective img to window failed", map);
		if (mlx_image_to_window(map->mlx, map->img[YUMMY], \
	num->j * PIXEL, num->i * PIXEL) < 0)
			errors("Yummy img to window failed", map);
	}
}

static void	wall_collectives_exit_img(t_maps *map, t_count *num)
{
	if (map->map[num->i][num->j] == '1')
	{
		if (mlx_image_to_window(map->mlx, map->img[WALL], \
		num->j * PIXEL, num->i * PIXEL) < 0)
			errors("Wall img to window failed", map);
	}
	if (map->map[num->i][num->j] == 'E')
	{
		if (mlx_image_to_window(map->mlx, map->img[EXIT_CLOSE], \
	num->j * PIXEL, num->i * PIXEL) < 0)
			errors("Exit_close img to window failed", map);
		if (mlx_image_to_window(map->mlx, map->img[EXIT_OPEN], \
	num->j * PIXEL, num->i * PIXEL) < 0)
			errors("Exit_open img to window failed", map);
		disable_exit(map);
		img_onoff(map, EXIT_CLOSE, true);
	}
	wall_collectives(map, num);
}

static void	ply_enemy_img(t_maps *map, t_count *num)
{
	num->i = 0;
	while (num->i <= map->height && map->map[num->i])
	{
		num->j = 0;
		while (num->j <= map->width && map->map[num->i][num->j])
		{
			if (map->map[num->i][num->j] == 'P')
			{
				player_img(map, num);
				disable_ply(map);
				img_onoff(map, PLY_START, true);
			}
			num->j++;
		}
		num->i++;
	}
}

void	img_to_window(t_maps *map, t_count *num)
{
	map->tmp = 0;
	num->i = 0;
	while (num->i <= map->height && map->map[num->i])
	{
		num->j = 0;
		while (num->j <= map->width && map->map[num->i][num->j])
		{
			if (mlx_image_to_window(map->mlx, map->img[BG], \
			num->j * PIXEL, num->i * PIXEL) < 0)
				errors("Backgroud img to window failed", map);
			wall_collectives_exit_img(map, num);
			num->j++;
		}
		num->i++;
	}
	ply_enemy_img(map, num);
	while (map->tmp < map->collectives)
	{
		map->img[YUMMY]->instances[map->tmp].enabled = false;
		map->tmp++;
	}
	map->tmp = 0;
}
