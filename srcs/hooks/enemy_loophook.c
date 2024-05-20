/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_loophook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:47 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/20 15:45:29 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	enemy_img_direction(t_maps *map, int count, t_direct i)
{
	// map->enm_direction[count] = i;
	disable_enemy(map, count);
	if (i == UP)
	{
		// img_onoff(map, ENM_B, true);
		map->img[ENM_B]->instances[count].enabled = true;
		// map->enm_nowimg[count] = ENM_B;
	}
	if (i == DOWN)
	{
		// img_onoff(map, ENM_F, true);
		map->img[ENM_F]->instances[count].enabled = true;
		// map->enm_nowimg[count] = ENM_F;
	}
	if (i == LEFT)
	{
	// 	img_onoff(map, ENM_L, true);
		map->img[ENM_L]->instances[count].enabled = true;
		// map->enm_nowimg[count] = ENM_L;
	}
	if (i == RIGHT)
	{
		// img_onoff(map, ENM_R, true);
		map->img[ENM_R]->instances[count].enabled = true;
		// map->enm_nowimg[count] = ENM_R;
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
	// map->img[COLLISION]->instances[count].x = map->enemy[count].j * PIXEL;
	// map->img[COLLISION]->instances[count].y = map->enemy[count].i * PIXEL;
}

void	enemy_position(t_maps *map, int count, t_direct i)
{
	// 그래서 이렇게 따로 다른 function에 해줘야 가능? 하다고 보여진다.
	// if (map->img[COLLISION]->instances[count].x == map->enemy[count].j * PIXEL \
	// 	&& map->img[COLLISION]->instances[count].y == map->enemy[count].i * PIXEL)
	// 		map->img[COLLISION]->instances[count].enabled = false;
	if (i == UP)
		map->enemy[count].i--;
	if (i == DOWN)
		map->enemy[count].i++;
	if (i == LEFT)
		map->enemy[count].j--;
	if (i == RIGHT)
		map->enemy[count].j++;
}


void     enemy_generator(t_maps *map, int count)
{
	map->random[count].i = (rand() % 4) - 2;
	map->random[count].j = 0;
	if (map->random[count].i == 0)
		map->random[count].j = (rand() % 7) - 3;
	// printf("map->random[count].i : %d\n", map->random[count].i);
	if (map->random[count].i < 0) //UP
		enemy_img_direction(map, count, UP);
	else if (map->random[count].i > 0) //DOWN
		enemy_img_direction(map, count, DOWN);
	if (map->random[count].j < 0)// LEFT
		enemy_img_direction(map, count, LEFT);
	else if (map->random[count].j > 0) // RIGHT
		enemy_img_direction(map, count, RIGHT);
	// if (map->random[count].j == 0 || map->random[count].i == 0)
	// 	map->enm_nowimg[count] = ENM_F;
	// printf("map->random[count].i : %d\n", map->random[count].i);
	// printf("map->enm_direction[%d] : %d\n", count, map->enm_direction[count]);
}

void	encount_enemy(t_maps *map)
{
	int i;
	
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
		// if ((map->player.j * PIXEL == map->img[map->enm_nowimg[i]]->instances[i].x \
		// && map->player.i * PIXEL == map->img[map->enm_nowimg[i]]->instances[i].y))
		// if (map->player.j == map->enemy[i].j && map->player.i == map->enemy[i].i)
		{
			print_on_screen(map, "YOU LOST!", map->height);
			
			// mlx_loop_hook(map->mlx, ending_prints_lost, map);

			img_onoff(map, map->ply_nowimg, false);
			// if (map->img[COLLISION]->instances[count].x == map->player.j * PIXEL \
			// && map->img[COLLISION]->instances[count].y == map->player.i * PIXEL)
			// 	map->img[COLLISION]->instances[count].enabled = true;
			// disable_enemy(map, i);
			img_onoff(map, PLY_FAIL, true);
			map->status = LOST;
			mlx_key_hook(map->mlx, ending_prints, map);
		}
		i++;
	}
}

void	check_right_spot(t_maps *map, int count, int i)
{
	// printf("map->enemy[count].i : %d\n",map->enemy[count].i);
	the_next(map, map->enemy[count], i);
	// printf("next\n");
	if (map->map[map->next.i][map->next.j] != '1' && \
	(map->map[map->next.i][map->next.j] != 'E'))
	{
		enemy_position(map, count, i);
		// printf("map->map[map->enemy[%d].i][map->enemy[%c].j]: %c\n\n", count, count, map->map[map->enemy[count].i][map->enemy[count].j]);
		// encount_enemy(map);
		move_enemy_to_direction(map, count);
		// enemy_img_direction(map,count,i);
		if (map->collect_count == map->collectives)
		{
			img_onoff(map, EXIT_CLOSE, false);
			img_onoff(map, EXIT_OPEN, true);
		}
	}
	// printf("over\n");
	}

void     move_img_X(t_maps *map, int count)
{
	// printf("random[%d].j : %d\n", count, map->random[count].j);
	while (map->random[count].j < 0) // LEFT
	{
		check_right_spot(map, count, LEFT);
		map->random[count].j++;
	}
	while (map->random[count].j > 0) // RIGHT
	{
		check_right_spot(map, count, RIGHT);
		map->random[count].j--;
	}
}

void     move_img_Y(t_maps *map, int count)
{
	// printf("map->random->i[%d] : %d\n", count, map->random[count].i);
	while (map->random[count].i < 0)//UP
	{
		check_right_spot(map, count, UP);
		map->random[count].i++;
	}
	while (map->random[count].i > 0)//DOWN
	{
		check_right_spot(map, count, DOWN);
		map->random[count].i--;
	}
}

void	initial_enemy(t_maps *map, int count)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	map->random = (t_pos*)calloc(count, sizeof(t_pos));
	map->enm_nowimg = (int*)calloc(count, (sizeof(int)));
	// map->enm_direction = (int*)calloc(count, sizeof(int));
	if (!map->random || !map->enm_nowimg )//|| !map->enm_direction )
		errors("error occurred in calloc in initial_enemy()", map);
	// printf("count : %d\n", map->enemy_count);
	while (map->map[i][j] && i <= map->height && tmp <= count)
	{
		while (map->map[i][j] && j <= map->width && tmp <= count)
		{
			if (map->map[i][j] == 'X')
			{
				map->enemy[tmp] = (t_pos){i, j};
				// printf("map->enemy[%d] : {i : %d, j : %d}\n",tmp, map->enemy[tmp].i, map->enemy[tmp].j);
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
	
	map = (t_maps*)param;
	count = 0;
	// printf("\nenenies : %d\n", map->enemy_count);
	// printf("random.i[0]: %d\n",map->random.i[0]);
	// printf("map->enemy[count].i : %d\n",map->enemy[count].i);
	encount_enemy(map); // 먼저 안하면 빠르게 지나쳐버리면 인식하지않기때문에 필수!
	if (map->fps++ < 50)
		return;
	while (count < map->enemy_count)
	{
		printf("\ninside count : %d\n", count);
		enemy_generator(map, count);
		count++;
	}
	count = 0;
	printf("\ncount : %d\n", count);
	while (count < map->enemy_count && map->status == PLAYING)
	{
		move_img_X(map, count);
		move_img_Y(map, count);
		count++;
	}
	map->fps = 0;
}
