/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rantangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:29:55 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/14 15:16:34 by skwon2           ###   ########.fr       */
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

