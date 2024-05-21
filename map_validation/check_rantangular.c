/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rantangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:29:55 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/20 16:33:30 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_rectangular(t_maps *map)
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
