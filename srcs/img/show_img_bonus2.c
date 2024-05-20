/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_img_bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:30:36 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/20 16:31:31 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
	map->print_moves = mlx_put_string(map->mlx, "MOVES : 0", \
	((map->width / 2) - (ft_strlen("MOVES : 0") / 6.5)) \
	* PIXEL, (map->height - 3) * PIXEL / 2);
}
