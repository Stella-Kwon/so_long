/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_onoff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:22:17 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/15 16:07:08 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	img_onoff(t_maps *map, int i, bool d)
{
	map->img[i]->enabled = d;
}

void	disable_ply(t_maps *map)
{
	img_onoff(map, PLY_B, false);
	img_onoff(map, PLY_F, false);
	img_onoff(map, PLY_L, false);
	img_onoff(map, PLY_R, false);
	img_onoff(map, PLY_START, false);
}

void	bonus_disable_ply(t_maps *map)
{
	img_onoff(map, PLY_B, false);
	img_onoff(map, PLY_F, false);
	img_onoff(map, PLY_L, false);
	img_onoff(map, PLY_R, false);
	img_onoff(map, PLY_START, false);
	img_onoff(map, PLY_FAIL, false);
}

void	disable_enemy(t_maps *map)
{
	// img_onoff(map, ENM_B, false);
	// img_onoff(map, ENM_F, false);
	// img_onoff(map, ENM_L, false);
	// img_onoff(map, ENM_R, false);
	// img_onoff(map, COLLISION, false);
	int i;

	i = 0;
	while (i < map->enemy_count)
	{
		map->img[ENM_B]->instances[i].enabled = false;
		map->img[ENM_F]->instances[i].enabled = false;
		map->img[ENM_L]->instances[i].enabled = false;
		map->img[ENM_R]->instances[i].enabled = false;
	}
}

void	disable_exit(t_maps *map)
{
	img_onoff(map, EXIT_CLOSE, false);
	img_onoff(map, EXIT_OPEN, false);
}

