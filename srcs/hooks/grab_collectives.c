/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_collectives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:48:44 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/09 12:06:23 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	grab_collectives(t_maps *map, int i)
{
	int c;
	
	c = 0;
	printf("collect_count : %d\n", map->collect_count);
	while (c < map->collectives) // check which one is.
	{
		if (map->img[i]->instances[c].x == map->player.j * PIXEL \
		&& map->img[i]->instances[c].y == map->player.i * PIXEL)
		{
			// printf("ate\n");
			map->img[i]->instances[c].enabled = false;
			// img_onoff(map, i, false);
			// img_onoff(map, COLLISION, true);
			// img_onoff(map, COLLISION, false);
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
