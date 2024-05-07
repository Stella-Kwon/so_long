/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:02:18 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/08 01:50:02 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	the_next(t_maps *map, t_direct i)
{
	map->next = map->player;
	if (i == UP)
		map->next.i--;
	if (i == DOWN)
		map->next.i++;
	if (i == LEFT)
		map->next.j--;
	if (i == RIGHT)
		map->next.j++;
}

void	player_position(t_maps *map, t_direct i)
{
	disable_ply(map);
	if (i == UP)
	{
		img_onoff(map, PLY_B, true);
		map->player.i--;
		map->ply_nowimg = map->img[PLY_B];
		map->img[PLY_B]->instances[0].x = map->player.i * PIXEL;
		map->img[PLY_B]->instances[0].y = map->player.j * PIXEL;
	}
	if (i == DOWN)
	{
		img_onoff(map, PLY_F, true);
		map->player.i++;
		map->ply_nowimg = map->img[PLY_F];
		map->img[PLY_F]->instances[0].x = map->player.i * PIXEL;
		map->img[PLY_F]->instances[0].y = map->player.j * PIXEL;
	}
	if (i == LEFT)
	{
		img_onoff(map, PLY_L, true);
		map->player.j--;
		map->ply_nowimg = map->img[PLY_L];
		map->img[PLY_L]->instances[0].x = map->player.i * PIXEL;
		map->img[PLY_L]->instances[0].y = map->player.j * PIXEL;
	}	
	if (i == RIGHT)
	{
		img_onoff(map, PLY_R, true);
		map->player.j++;
		map->ply_nowimg = map->img[PLY_R];
		map->img[PLY_R]->instances[0].x = map->player.i * PIXEL;
		map->img[PLY_R]->instances[0].y = map->player.j * PIXEL;
	}	
	map->moves++;
}

void	move_player(t_maps *map, t_direct i)
{
	if (!map->collectives)
	{
		img_onoff(map, EXIT_CLOSE, false);
		img_onoff(map, EXIT_OPEN, true);
	}
	the_next(map, i);
	if ((map->next.i >= 0 && map->next.j >= 0) || \
	map->map[map->next.i][map->next.j] != 1)
	{
		if (map->map[map->next.i][map->next.j] == 'C')
			grab_collectives(map); // 만들어줘서 플레이어 위치와 같을때 collision해주고 바로 플레이어로 바꿔주기.
		player_position(map, i);
	}
	if (map->map[map->player.i][map->player.j] != 'E')
	{
		if (!map->collectives)
			img_onoff(map, map->ply_nowimg, false);
	}
	// enemy_move(); 를 만들고 loophook은 안에 들어갈 그 함수가 계속 프레임당 실행되니까 이걸 넣어 실행해주고...
	// 그리고나서 enemy를 만나면 Player는 죽는다는 걸 넣어주기.
}

void	player_keyhook(mlx_key_data_t keydata, void* param)
{
	t_maps	*map;

	map = (t_maps *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->mlx);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
	&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player(map, UP);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
	&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player(map, LEFT);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
	&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player(map, DOWN);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
	&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player(map, RIGHT);
}

