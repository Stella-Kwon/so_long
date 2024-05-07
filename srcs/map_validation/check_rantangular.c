/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rantangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:29:55 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/07 21:21:24 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// void	check_rectangular(t_maps *map)
// {
// 	int32_t	length;

// 	length = ft_strlen(map->map_oneline);
// 	if (length % (map->width + 1) != 0)
// 		errors("Not a rectangular shape : Invalid map", map);
// }

void	check_rectangular(t_maps *map) // in 2d array
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	j = 0;
	while (map->map[i] && i <= map->height)
	{
		j = 0;
		while (map->map[i][j] && j <= map->width)
			j++;
		tmp = j - 1;
		if (tmp != map->width)
			errors("Not a rectangular shape : Invalid map", map);
		i++;	
	}
}

