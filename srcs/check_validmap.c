/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:30:08 by skwon2            #+#    #+#             */
/*   Updated: 2024/04/26 14:28:27 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	check_rectangular(t_maps *map)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	j = 0;
	while (map->map[i][j] && i <= map->height)
	{
		if (tmp != j)
			return (error("Not a rectangular shape : Invalid map"));
		j++;
		tmp = j;
	}
	j--;
	if (j != map->width)
		return (error("Not equal to map->width : Invalid map"));
	return (SUCCESS);
}

int	check_wall(t_maps *map)
{
	int	i;

	i = 1;
	if (check_each_line(map, 0) == FAILURE || \
	check_each_line(map, map->height) == FAILURE)
		return (error("Not surrounded by wall : Invalid map"));
	while (map->map[i] && i < map->height)
	{
		if (map->map[i][0] != 1 || map->map[i][map->height] != 1)
			return (error("Not surrounded by wall : Invalid map"));
		i++;
	}
	return (SUCCESS);
}

int	eachline_count_sprites(t_maps *map, t_count *num)
{
	while (map->map[num->i][num->j] && num->j <= map->width)
	{
		if (map->map[num->i][num->j] == 'P')
		{
			map->exit = (t_pos){num->i, num->j};
			num->player++;
		}
		else if (map->map[num->i][num->j] == 'C')
			map->collectives;
		else if (map->map[num->i][num->j] == 'E')
		{
			map->exit = (t_pos){num->i, num->j};
			num->exit++;
		}
		else
		{
			if (check_else_char(map->map[num->i][num->j]) == FAILURE)
				return (FAILURE);
		}
		num->j++;
	}
}

int	check_instance_count(t_maps *map)
{
	t_count num;

	num->exit = 0;
	num->player = 0;
	num->i = 0;
	num->j = 0;

	while (map->map[num->i][num->j] &&  num->i < map->height)
	{

		num->i++;
	}

	if (exit != 1 || player != 1 || map->collectives < 1)
		return (error("Not right number of instances : Invalid map"));
	return (SUCCESS);
}

int	check_else_char(char c)
{
	if (ft_strchr("01CEP", c) == NULL)
		return (error("Other character than 0 1 C E P : Invalid map"));
	return (SUCCESS);
}