/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_too_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:11:45 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/21 13:57:18 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	map_too_big(t_maps *map)
{
	// int32_t	width;
	// int32_t	height;

	// mlx_get_monitor_size(0, &width, &height);
	// printf("width: %d \nheight : %d\n", width, height); this one does not work for some reason. gives 0 all the time
	if (map->width * PIXEL > 1920 || map->height * PIXEL > 1080)
		errors("Map too big : Invalid map", map);
}
