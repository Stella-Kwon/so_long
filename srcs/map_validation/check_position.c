/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:39:45 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/16 11:34:41 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	flood_fill(t_maps *map, t_count *num, int32_t i, int32_t j)
{
	if (j < 0 || i < 0)
		return (0);
	if (map->maptmp[i][j] == 'E' && num->collectives == map->collectives)
		num->exit++;
	if (map->maptmp[i][j] == 'C')
		num->collectives++;
	map->maptmp[i][j] = '1';
	if (map->maptmp[i + 1][j] != '1')
		flood_fill(map, num, i + 1, j);
	if (map->maptmp[i - 1][j] != '1')
		flood_fill(map, num, i - 1, j);
	if (map->maptmp[i][j + 1] != '1')
		flood_fill(map, num, i, j + 1);
	if (map->maptmp[i][j - 1] != '1')
		flood_fill(map, num, i, j - 1);
	if (num->exit != 1 || num->collectives != map->collectives)
		return (1);
	return (0);
}

void	check_position(t_maps *map, t_count *num)
{
	map->maptmp = ft_split(map->map_oneline, '\n');
	num->j = map->player.j;
	num->i = map->player.i;
	num->exit = 0;
	num->collectives = 0;

	if (flood_fill(map, num, num->i, num->j) == 1)
		errors("Not in a right format : Invalid map", map);
}
