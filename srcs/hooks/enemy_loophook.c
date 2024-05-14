/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_loophook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:47 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/13 14:14:33 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	enemy_img_direction(t_maps *map, int count, t_direct i)
{
	map->enm_nowimg = (int*)calloc(count, (sizeof(int)));
	if (!map->enm_nowimg)
		errors("error occurred in calloc while enemy_img_direction", map);
	map->enm_direction[count] = i;
	disable_enemy(map);
	if (i == UP)
	{
		map->img[ENM_B]->instances[count].enabled = true;
		map->enm_nowimg[count] = ENM_B;
	}
	if (i == DOWN)
	{
		map->img[ENM_F]->instances[count].enabled = true;
		map->enm_nowimg[count] = ENM_F;
	}
	if (i == LEFT)
	{
		map->img[ENM_L]->instances[count].enabled = true;
		map->enm_nowimg[count] = ENM_L;
	}
	if (i == RIGHT)
	{
		map->img[ENM_R]->instances[count].enabled = true;
		map->enm_nowimg[count] = ENM_R;
	}
}

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
	map->img[COLLISION]->instances[count].x = map->enemy[count].j * PIXEL;
	map->img[COLLISION]->instances[count].y = map->enemy[count].i * PIXEL;
}

void	enemy_position(t_maps *map, int count, t_direct i)
{
	//그래서 이렇게 따로 다른 function에 해줘야 가능? 하다고 보여진다.
	if (map->img[COLLISION]->instances[count].x == map->enemy[count].j * PIXEL \
		&& map->img[COLLISION]->instances[count].y == map->enemy[count].i * PIXEL)
			map->img[COLLISION]->instances[count].enabled = false;
	if (i == UP)
		map->enemy[count].i--;
	if (i == DOWN)
		map->enemy[count].i++;
	if (i == LEFT)
		map->enemy[count].j--;
	if (i == RIGHT)
		map->enemy[count].j++;
}


void     enemy_generator(t_maps *map, int count, t_random *random)
{
	
	random->i[count] = (rand() % 4) - 2;
	random->j[count] = (rand() % 7) - 3;
	printf("count : %d\n", count);
	if (random->i[count] < 0) //UP
		enemy_img_direction(map, count, UP);
	else if (random->i[count] > 0) //DOWN
		enemy_img_direction(map, count, DOWN);
	if (random->j[count] < 0)// LEFT
		enemy_img_direction(map, count, LEFT);
	else if (random->j[count] > 0) // RIGHT
		enemy_img_direction(map, count, RIGHT);
}

void	check_right_spot(t_maps *map, int count, int i)
{
	the_next(map, map->enemy[count], i);
	if (map->map[map->next.i][map->next.j] != '1' && \
	(map->map[map->next.i][map->next.j] != 'E'))
	{
		enemy_position(map, count, i);
		printf("map->map[map->enemy[%d].i][map->enemy[%c].j]: %c\n\n", count, count, map->map[map->enemy[count].i][map->enemy[count].j]);
		if (map->map[map->player.i][map->player.j] == map->map[map->enemy[count].i][map->enemy[count].j] )
		{
			img_onoff(map, map->ply_nowimg, false);
			if (map->img[COLLISION]->instances[count].x == map->player.j * PIXEL \
			&& map->img[COLLISION]->instances[count].y == map->player.i * PIXEL)
				map->img[COLLISION]->instances[count].enabled = true;
			img_onoff(map, PLY_FAIL, true);
		}
		move_enemy_to_direction(map, count);
	}
}

void     move_img_X(t_maps *map, int count, t_random *random)
{
	while (random->j[count] < 0) // LEFT
	{
		check_right_spot(map, count, LEFT);
		random->j[count]++;
	}
	while (random->j[count] > 0) // RIGHT
	{
		check_right_spot(map, count, RIGHT);
		random->j[count]--;
	}
}

void     move_img_Y(t_maps *map, int count, t_random *random)
{
	while (random->i[count] < 0)//UP
	{
		check_right_spot(map, count, UP);
		random->i++;
	}
	while (random->i[count] > 0)//DOWN
	{
		check_right_spot(map, count, DOWN);
		random->i--;
	}
}



void	initial_enemy(t_maps *map, t_random *random, int count)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	random->i = (int*)calloc(count, sizeof(int32_t));
	random->j = (int*)calloc(count, sizeof(int32_t));
	map->enm_direction = (int*)calloc(count, sizeof(int));
	map->enemy = (t_pos *)calloc(count, sizeof(t_pos));
	if (!random->j || !random->i || !map->enm_direction || !map->enemy)
		errors("error occurred in calloc in initial_enemy()", map);
	while (map->map[i][j] && i <= map->height && tmp < count)
	{
		while (map->map[i][j] && j <= map->width && tmp < count)
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


void	move_enemy(void *param) 
{
	t_maps *map;
	int count;
	t_random    random;
	
	map = (t_maps*)param;
	count = 0;
	initial_enemy(map, &random, map->enemy_count);
	while (count < map->enemy_count)
	{
		enemy_generator(map, count, &random);
		count++;
	}
	count = 0;
	while (count < map->enemy_count)
	{
		move_img_X(map, count, &random);
		move_img_Y(map, count, &random);
		count++;
	}
}
