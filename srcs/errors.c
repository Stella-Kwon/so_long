/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:57:13 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/23 14:10:53 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**all_free(char ***res, int number)
{
	int	i;

	i = 0;
	if (!(*res) || !(*res)[i])
		return (NULL);
	while ((*res)[i] && i <= number)
	{
		free ((*res)[i]);
		(*res)[i] = NULL;
		i++;
	}
	free(*res);
	*res = NULL;
	return (NULL);
}

void	free_null(char **res)
{
	if (*res)
	{
		free(*res);
		*res = NULL;
	}
}

void	free_every(t_maps *map)
{
	if (map->line)
		free_null(&map->line);
	if (map->oneline_tmp)
		free_null(&map->oneline_tmp);
	if (map->map)
		all_free(&map->map, map->height);
	if (map->maptmp)
		all_free(&map->maptmp, map->height);
	if (map->map_oneline)
		free_null(&map->map_oneline);
	if (map->random)
		free_null((char **)&map->random);
	if (map->enemy)
		free_null((char **)&map->enemy);
}

void	errors(char *mes, t_maps *map)
{
	if (!mes)
		ft_putendl_fd("Error.", 2);
	else
	{
		ft_putstr_fd ("Error : ", 2);
		ft_putendl_fd(mes, 2);
	}
	free_every(map);
	exit(FAILURE);
}
