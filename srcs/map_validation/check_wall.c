/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:30:08 by skwon2            #+#    #+#             */
/*   Updated: 2024/04/29 14:40:41 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_each_line(t_maps *map, int i)
{
	int	j;

	j = 0;
	while (map->map[i][j] && j <= map->width)
	{
		if (map->map[i][j] != 1)
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

void	check_wall(t_maps *map)
{
	int	i;

	i = 1;
	if (check_each_line(map, 0) == FAILURE || \
	check_each_line(map, map->height) == FAILURE)
		error("Not surrounded by wall : Invalid map");
	while (map->map[i] && i < map->height)
	{
		if (map->map[i][0] != 1 || map->map[i][map->height] != 1)
			error("Not surrounded by wall : Invalid map");
		i++;
	}
}



