/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:02:18 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/09 12:04:58 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	the_next(t_maps *map, t_direct i)
{
	map->next = map->player;
	if (i == UP) //&& map->next.i > 0)
		map->next.i--;
	if (i == DOWN) //&& map->next.j < map->height)
		map->next.i++;
	if (i == LEFT) //&& map->next.j > 0)
		map->next.j--;
	if (i == RIGHT) //&& map->next.j < map->width)
		map->next.j++;
	printf("\n\nthe next : \n");
	printf("map->next.i : %d\n", map->next.i);
	printf("map->next.j : %d\n\n", map->next.j);
	printf("map->map[map->next.i][map->next.j] : %c\n\n", map->map[map->next.i][map->next.j]);
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
	if (i == UP)
		map->player.i--;
		/*
		map->img[PLY_B]->instances[0].x = map->player.j * PIXEL;
		map->img[PLY_B]->instances[0].y = map->player.i * PIXEL;
		printf("map->img[PLY_B]->instances[0].x : %d\n", map->img[PLY_B]->instances[0].x);
		printf("map->img[PLY_B]->instances[0].y : %d\n", map->img[PLY_B]->instances[0].y);
		이렇게 하면 오버랩되서 플레이어가 보이지않음. 언제 어떤 이미지를 끄고 뭐가 먼저 오느냐에 따라 달라지는듯.
		*/
	if (i == DOWN)
		map->player.i++;
		/*
			map->img[PLY_F]->instances[0].x = map->player.j * PIXEL;
		map->img[PLY_F]->instances[0].y = map->player.i * PIXEL;
		printf("map->img[PLY-F]->instances[0].x : %d\n", map->img[PLY_F]->instances[0].x);
		printf("map->img[PLY_F]->instances[0].y : %d\n", map->img[PLY_F]->instances[0].y);
		*/
	if (i == LEFT)
			map->player.j--;
		/*
			map->img[PLY_L]->instances[0].x = map->player.j * PIXEL;
		map->img[PLY_L]->instances[0].y = map->player.i * PIXEL;
		printf("map->img[PLY_L]->instances[0].x : %d\n", map->img[PLY_L]->instances[0].x);
		printf("map->img[PLY_L]->instances[0].y : %d\n", map->img[PLY_L]->instances[0].y);
		*/
	if (i == RIGHT)
		map->player.j++;
		/*
			map->img[PLY_R]->instances[0].x = map->player.j * PIXEL;
		map->img[PLY_R]->instances[0].y = map->player.i * PIXEL;
		printf("map->img[PLY_R]->instances[0].x : %d\n", map->img[PLY_R]->instances[0].x);
		printf("map->img[PLY_R]->instances[0].y : %d\n", map->img[PLY_R]->instances[0].y);
		*/
	map->moves++;
}

void move_player_to_direction(t_maps *map)
{
	map->img[PLY_B]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_B]->instances[0].y = map->player.i * PIXEL;
	map->img[PLY_F]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_F]->instances[0].y = map->player.i * PIXEL;
	map->img[PLY_L]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_L]->instances[0].y = map->player.i * PIXEL;
	map->img[PLY_R]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_R]->instances[0].y = map->player.i * PIXEL;
	map->img[PLY_FAIL]->instances[0].x = map->player.j * PIXEL;
	map->img[PLY_FAIL]->instances[0].y = map->player.i * PIXEL;
}

void	player_move(t_maps *map, t_direct i)
{
	the_next(map, i);
	// printf("\n\nthe player: \n");
	// printf("map->player.i : %d\n", map->player.i);
	// printf("map->player.j : %d\n\n", map->player.j);
	player_img_direction(map, i);
	if (map->map[map->next.i][map->next.j] != '1' && \
	(map->map[map->next.i][map->next.j] != 'E'))
	{
		player_position(map, i);
		printf("collect_count : %d\n", map->collectives);
		printf("collect_count : %d\n", map->collect_count);
		printf("map->map[map->player.i][map->player.j]: %c\n\n", map->map[map->player.i][map->player.j]);
		if (map->map[map->player.i][map->player.j] == 'C')
			grab_collectives(map, COLLECTIVE); // 만들어줘서 플레이어 위치와 같을때 collision해주고 바로 플레이어로 바꿔주기.
		move_player_to_direction(map);
	}
	if (map->map[map->next.i][map->next.j] == 'E' && map->collect_count == map->collectives)
	{
		player_position(map, i);
		move_player_to_direction(map);
		img_onoff(map, map->ply_nowimg, false);
		map->status = WON;
		mlx_key_hook(map->mlx, ending_prints, map);
		// ending_prints(map, WON); // 이렇게 하면 안돼. 플레이어가 계속 움직여
	}
	print_moves(map);
	// enemy_move(); 를 만들고 loophook은 안에 들어갈 그 함수가 계속 프레임당 실행되니까 이걸 넣어 실행해주고...
	// 그리고나서 enemy를 만나면 Player는 죽는다는 걸 넣어주기.
}


// void	player_keyhook(mlx_key_data_t keydata, void* param)
// {
// 	t_maps	*map;

// 	map = (t_maps *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE)
// 		mlx_close_window(map->mlx);
// 	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
// 	&& (keydata.action == MLX_PRESS))
// 		player_move(map, UP);
// 	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
// 	&& (keydata.action == MLX_PRESS))
// 		player_move(map, LEFT);
// 	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
// 	&& (keydata.action == MLX_PRESS))
// 		player_move(map, DOWN);
// 	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
// 	&& (keydata.action == MLX_PRESS))
// 		player_move(map, RIGHT);
// }

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

