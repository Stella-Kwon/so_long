/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:39:45 by skwon2            #+#    #+#             */
/*   Updated: 2024/04/29 15:56:04 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void check_position(t_maps *map, t_count num) //player && exit ONLY THOSE TWO SHOULD BE NOY COVERED BY WALL '1' / SO ONLY ONE CONDITION TO CHECK IS THAT EXIT AND PLAYER
{
    num.i = 0;
    num.j = 0;
    
    if (map->width < num.j && map->height < num.i && num.j < 0 &&  num.i < 0 && map->map[num.i][num.j] == 1)
        return (0);
    if ()
}