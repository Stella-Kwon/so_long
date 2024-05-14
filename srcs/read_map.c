/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:37:25 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/14 15:26:14 by skwon2           ###   ########.fr       */
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
		map->line = get_next_line(fd);
		if (map->line)
		{
			map->height++;
			if (ft_strncmp(map->line, "\n", 1) == 0)
				errors("Map has empty line in the middle", map);
		}
	}
	map->map = ft_split(map->map_oneline, '\n');
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
	map->width = ft_strlen(map->line) - 2;
	each_line(map, fd);
	return (SUCCESS);
}
