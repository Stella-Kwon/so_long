/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:37:25 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/07 23:05:31 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	each_line(t_maps *map, int fd)
{
	while (map->line)
	{
		map->map_oneline = ft_strjoin(map->map_oneline, map->line);
		if (!map->map_oneline)
			errors("Map reading malloc failed", map);
		// printf("map_oneline : %s\n", map->map_oneline);
		map->line = get_next_line(fd);
		// Becasue when it reaches EOF, return value will be NULL as well.
		// if (!(map->line))
		// 	errors("Malloc error while reading the map", map);
		// printf("map line : %s\n", map->line);
		if (map->line)
		{
			map->height++;
			if (ft_strncmp(map->line, "\n", 1) == 0)
				errors("Map has empty line in the middle", map);
		}
	}
	// printf("height : %d\n", map->height);
	map->map = ft_split(map->map_oneline, '\n');
	char **current = map->map; // 현재 포인터를 가리킬 변수 추가
	while (*current)
	{
		printf("map[] : %s\n", *current);
		current++; // 다음 문자열로 이동
	}
	if (!map->map)
		errors("Split error in the each_line function", map);
}

int	read_map(char *file, t_maps *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		errors("Open the map failed.", map);
	map->line = get_next_line(fd);
	//because of when the text EOF, it returns also NULL;
	// if (!(map->line))
	// 	errors("Malloc error while reading the map or nothing to read", map);
	map->width = ft_strlen(map->line) - 2; // -2 because of '\n'
	each_line(map, fd);
	return (SUCCESS);
}
