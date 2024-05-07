/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:59:32 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/08 00:03:03 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ESC_print(mlx_key_data_t keydata, t_maps *map)
{
	mlx_put_string(map->mlx, "ESC to exit", (map->width - ft_strlen("\"ESC to exit\"") / 2) \
	* PIXEL / 2, map->height * PIXEL / 2);
}

void	enemy_hook(mlx_key_data_t keydata, void* param);
