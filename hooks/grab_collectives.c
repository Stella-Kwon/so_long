/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_collectives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:48:44 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/20 16:21:58 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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

void	grab_collectives(t_maps *map, int i)
{
	int	c;

	c = 0;
	map->tmp = 0;
	img_onoff(map, map->ply_nowimg, false);
	while (c < map->collectives)
	{
		if (map->img[i]->instances[c].x == map->player.j * PIXEL \
		&& map->img[i]->instances[c].y == map->player.i * PIXEL)
			map->img[i]->instances[c].enabled = false;
		if (map->img[YUMMY]->instances[c].x == map->player.j * PIXEL \
		&& map->img[YUMMY]->instances[c].y == map->player.i * PIXEL)
		{
			map->img[YUMMY]->instances[c].enabled = true;
			map->tmp = c;
		}
		c++;
	}
	map->map[map->player.i][map->player.j] = '0';
	map->collect_count++;
	if (map->collect_count == map->collectives)
	{
		img_onoff(map, EXIT_CLOSE, false);
		img_onoff(map, EXIT_OPEN, true);
	}
}
