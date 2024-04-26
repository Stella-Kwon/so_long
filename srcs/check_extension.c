/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:56:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/04/26 13:30:07 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_extension(char *file)
{
	int	pos;

	pos = ft_strlen(file) - 1;
	if (ft_strncmp(file + pos - 4, ".ber", 4) < 0)
		return (errors("invalid file extension"));
	return (SUCCESS);
}

int	each_line(t_maps *map, char **line, int fd)
{
	while (*line)
	{
		map->map = ft_strjoin(map->map, *line);
		if (!map->map)
			return (error("Map reading malloc failed"));
		printf("map : %s\n", map->map);
		map->height++;
		*line = get_next_line(fd);
		if (!*line)
			return (error("Malloc error while reading the map"));
	}
	map->map = ft_split(map->map_oneline, '\n');
	if (!map->map)
		return (error("Split error in the each_line function"));
}

int	read_map(char *file, t_maps *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (errors("Open the map failed."));
	line = get_next_line(fd);
	if (!line)
		return (error("Malloc error while reading the map"));
	map->width = ft_strlen(line) - 1;
	map->height++;
	if (each_line(map, &line, fd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}