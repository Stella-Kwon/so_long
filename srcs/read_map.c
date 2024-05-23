/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:37:25 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/23 13:53:48 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	each_line(t_maps *map, int fd)
{
	// Read each line and concatenate it into map->map_oneline
	while (map->line)
	{
		char *tmp = ft_strjoin(map->map_oneline, map->line);
		if (!tmp)
			errors("Map reading malloc failed", map);
		free_null(&map->map_oneline); // Free the previous concatenated string -> "" tobe null
		map->map_oneline = tmp; // Update with the new concatenated string -> so oneline will direct to tmp address and later it will free the tmp as well
		map->height++;
		if (ft_strncmp(map->line, "\n", 1) == 0)
			errors("Map has empty line in the middle", map);
		free_null(&map->line); // Free the current line after processing
		map->line = get_next_line(fd); // Read the next line
	}
	// Check for an empty line at the end of the map
	if (map->map_oneline[ft_strlen(map->map_oneline) - 1] == '\n')
		errors("Empty line at the end of the map", map);
	// Split the concatenated string into an array of strings
	map->map = ft_split(map->map_oneline, '\n');
	if (!map->map)
		errors("Split error in the each_line function or empty map", map);
}

int	read_map(char *file, t_maps *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		errors("Open the map failed.", map);
	map->line = get_next_line(fd);
	map->map_oneline = ft_strdup("");// Initialize map_oneline with an empty string
	if (!map->map_oneline)
		errors("Initial map_oneline malloc failed", map);
	map->width = ft_strlen(map->line) - 2;
	each_line(map, fd);
	close(fd);
	return (SUCCESS);
}
