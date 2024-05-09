/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:39:45 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/08 12:12:56 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	flood_fill(t_maps *map, t_count *num, int32_t i, int32_t j)
//player위치에서 부터 시작.....
// exit && collectables 이 다 있는지 확인하면 이게 제대로 전체적으로 돌아갔다는 소리야.
{
	if (j < 0 || i < 0)
		return (0);
	if (map->maptmp[i][j] == 'E')
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
	// printf("num exit : %d\n", num->exit);
	// printf("num colletives : %d\n", num->collectives);
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
	
	// printf("num exit : %d\n", num->exit);
	// printf("num colletives : %d\n", num->collectives);
	// printf("map colletives : %d\n", map->collectives);
	if (flood_fill(map, num, num->i, num->j) == 1)
		errors("Not in a right format : Invalid map", map);
	// all_free(map->maptmp);
}
