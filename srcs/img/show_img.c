/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:01:28 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/07 23:34:26 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	player_img(t_maps *map, t_count *num)
{
	if (mlx_image_to_window(map->mlx, map->img[PLY_START],\
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Player_start img to window failed", map);
	if (mlx_image_to_window(map->mlx, map->img[PLY_FAIL], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Player_fail img to window failed", map);
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

static void	enemy_img(t_maps *map, t_count *num)
{	
	if (mlx_image_to_window(map->mlx, map->img[ENM_R], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Enemy_right img to window failed", map);
	if (mlx_image_to_window(map->mlx, map->img[ENM_L], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Enemy_left img to window failed", map);
	if (mlx_image_to_window(map->mlx, map->img[ENM_F], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Enemy_front img to window failed", map);
	if (mlx_image_to_window(map->mlx, map->img[ENM_B], \
	num->j * PIXEL, num->i * PIXEL) < 0)
		errors("Enemy_back img to window failed", map);
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
	// 	if (mlx_image_to_window(map->mlx, map->img[EXIT_OPEN], \
	// num->j * PIXEL, num->i * PIXEL) < 0)
	// 		errors("Exit_open img to window failed", map);
	}
	if (map->map[num->i][num->j] == 'C')
	{
		if (mlx_image_to_window(map->mlx, map->img[COLLECTIVE], \
	num->j * PIXEL, num->i * PIXEL) < 0)
			errors("Collective img to window failed", map);
	}
}

static void	ply_enemy_img(t_maps *map, t_count *num)
{
	if (map->map[num->i][num->j] == 'P')
	{
		player_img(map, num);
		disable_ply(map);
		img_onoff(map, PLY_START, true);
	}
	if (map->map[num->i][num->j] == 'X')
	{
		enemy_img(map, num);
		disable_enemy(map);
		img_onoff(map, ENM_F, true);
	}
}

void	img_to_window(t_maps *map, t_count *num)
{
	num->i = 0;
	while (num->i <= map->height && map->map[num->i])
	{
		printf("i : %d\n", num->i);
		num->j = 0;
		while (num->j <= map->width && map->map[num->i][num->j])
		{
			printf("map->map[num->i][num->j] : %c\n",map->map[num->i][num->j]);
			printf("j : %d\n", num->j);
			if (mlx_image_to_window(map->mlx, map->img[BG], \
			num->j * PIXEL, num->i * PIXEL) < 0)
				errors("Backgroud img to window failed", map);
			wall_collectives_exit_img(map, num);
			ply_enemy_img(map, num);
			num->j++;
		}
		num->i++;
	}
}
