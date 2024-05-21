/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_too_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:11:45 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/21 14:17:42 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	map_too_big(t_maps *map)
{
	if (map->width * PIXEL > 1920 || map->height * PIXEL > 1080)
		errors("Map too big : Invalid map", map);
}
