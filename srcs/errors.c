/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:57:13 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/09 15:29:53 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*all_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free (res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	res = NULL;
	return (NULL);
}

void	free_every(t_maps *map)
{
	if (map->map)
		all_free(map->map);
	if (map->maptmp)
		all_free(map->maptmp);
	if (map->map_oneline)
		free(map->map_oneline);
	// double free errors
	// if (map->texture) 
	// 	mlx_delete_texture(map->texture);
	// if (map->mlx)
	// 	mlx_terminate(map->mlx);
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
