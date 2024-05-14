/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instances_count_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:34:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/14 15:38:49 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_else_char(char c, t_maps *map)
{
	if (ft_strchr("01CEP", c) == NULL)
		errors("Other character than 0 1 C E P : Invalid map", map);
}

void	eachline_count_sprites(t_maps *map, t_count *num)
{
	num->j = 0;
	while (map->map[num->i][num->j] && num->j <= map->width)
	{
		if (map->map[num->i][num->j] == 'P')
		{
			map->player = (t_pos){num->i, num->j};
			num->player++;
		}
		else if (map->map[num->i][num->j] == 'C')
			num->collectives++;
		else if (map->map[num->i][num->j] == 'X')
			num->enemies++;
		else if (map->map[num->i][num->j] == 'E')
		{
			map->exit = (t_pos){num->i, num->j};
			num->exit++;
		}
		else
			check_else_char(map->map[num->i][num->j], map);
		num->j++;
	}
}

void	check_instance_count(t_maps *map, t_count *num)
{
	while (map->map[num->i]&& num->i <= map->height)
	{
		eachline_count_sprites(map, num);
		num->i++;
	}
	map->collectives = num->collectives;
	if (num->exit != 1 || num->player != 1 \
	|| num->collectives < 1 || num->enemies < 1)
		errors("Not right number of instances : Invalid map", map);
}