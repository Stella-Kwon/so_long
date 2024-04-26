/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:51:15 by skwon2            #+#    #+#             */
/*   Updated: 2024/04/25 15:33:16 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    initialize(t_maps *map)
{
    map->width = 0;
	map->height = 0;
	map->map_oneline = NULL;
	map->map = NULL;
	map->collectives = 0;
}

int main(int argc, char **argv)
{
    t_maps map;

    if (argc != 2)
        return (errors("No map"));
    initialize(&map);
    if (check_extension(argv[1]) == FAILURE)
        return (FAILURE);
    
    
    return (0);
}