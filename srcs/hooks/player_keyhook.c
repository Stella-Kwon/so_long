/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:02:18 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/16 11:33:47 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	the_next(t_maps *map, t_pos next, t_direct i)
{
	map->next = next;
	if (i == UP)
		map->next.i--;
	if (i == DOWN)
		map->next.i++;
	if (i == LEFT)
		map->next.j--;
	if (i == RIGHT)
		map->next.j++;
}

void	player_img_direction(t_maps *map, t_direct i)
{
	disable_ply(map);
	if (i == UP)
	{
		img_onoff(map, PLY_B, true);
		map->ply_nowimg = PLY_B;
	}
	if (i == DOWN)
	{
		img_onoff(map, PLY_F, true);
		map->ply_nowimg = PLY_F;
	}
	if (i == LEFT)
	{
		img_onoff(map, PLY_L, true);
		map->ply_nowimg = PLY_L;
	}
	if (i == RIGHT)
	{
		img_onoff(map, PLY_R, true);
		map->ply_nowimg = PLY_R;
	}
}

void	player_position(t_maps *map, t_direct i)
{
	printf("map->tmp : %d\n", map->tmp);
	if (map->img[YUMMY]->instances[map->tmp].x == map->player.j * PIXEL \
		&& map->img[YUMMY]->instances[map->tmp].y == map->player.i * PIXEL)
		map->img[YUMMY]->instances[map->tmp].enabled = false;
	printf("\ndd\n");
	if (i == UP)
		map->player.i--;
	if (i == DOWN)
		map->player.i++;
	if (i == LEFT)
		map->player.j--;
	if (i == RIGHT)
		map->player.j++;
	map->moves++;
}

void	move_player_to_direction(t_maps *map)
{
	map->img[PLY_B]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_B]->instances[0].y = map->player.i * PIXEL;
	map->img[PLY_F]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_F]->instances[0].y = map->player.i * PIXEL;
	map->img[PLY_L]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_L]->instances[0].y = map->player.i * PIXEL;
	map->img[PLY_R]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_R]->instances[0].y = map->player.i * PIXEL;
}

void	player_move(t_maps *map, t_direct i)
{
	the_next(map, map->player, i);
	player_img_direction(map, i);
	if (map->map[map->next.i][map->next.j] != '1' && \
	(map->map[map->next.i][map->next.j] != 'E'))
	{
		player_position(map, i);
		
		if (map->map[map->player.i][map->player.j] == 'C')
			grab_collectives(map, COLLECTIVE);
		move_player_to_direction(map);
	}
	if (map->map[map->next.i][map->next.j] == 'E' && map->collect_count == map->collectives)
	{
		player_position(map, i);
		move_player_to_direction(map);
		img_onoff(map, map->ply_nowimg, false);
		map->status = WON;
		mlx_key_hook(map->mlx, ending_prints, map);
	}
	print_moves(map);
}

void	player_keyhook(mlx_key_data_t keydata, void* param)
{
	t_maps	*map;

	map = (t_maps *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->mlx);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
	&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		player_move(map, UP);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
	&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		player_move(map, LEFT);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
	&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		player_move(map, DOWN);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
	&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		player_move(map, RIGHT);
}

