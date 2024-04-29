/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instances_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:34:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/04/29 14:44:42 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


void	check_else_char(char c)
{
	if (ft_strchr("01CEP", c) == NULL)
		error("Other character than 0 1 C E P : Invalid map");
}

void	eachline_count_sprites(t_maps *map, t_count *num)
{
	while (map->map[num->i][num->j] && num->j <= map->width)
	{
		if (map->map[num->i][num->j] == 'P')
		{
			map->player = (t_pos){num->i, num->j};
			printf("map->player : { %d, %d}\n", num->i, num->j);
			num->player++;
		}
		else if (map->map[num->i][num->j] == 'C')
			map->collectives;
		else if (map->map[num->i][num->j] == 'E')
		{
			map->exit = (t_pos){num->i, num->j};
			printf("map->exit : { %d, %d}\n", num->i, num->j);
			num->exit++;
		}
		else
			check_else_char(map->map[num->i][num->j]);
		num->j++;
	}
}

void	check_instance_count(t_maps *map)
{
	t_count	num;

	num.exit = 0;
	num.player = 0;
	num.i = 0;
	num.j = 0;

	while (map->map[num.i][num.j] && num.i < map->height)
	{
		eachline_count_sprites(map, &num);
		num.i++;
	}
	if (num.exit != 1 || num.player != 1 || map->collectives < 1)
		error("Not right number of instances : Invalid map");
}
