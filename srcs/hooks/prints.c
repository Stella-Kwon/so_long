/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:59:32 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/14 15:59:19 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_on_screen(t_maps *map, char *line, int32_t height)
{
	mlx_put_string(map->mlx, line, ((map->width / 2) - (ft_strlen(line) / 6.5)) \
	* PIXEL, height * PIXEL / 2);
}

void	ending_prints(mlx_key_data_t keydata, void *param)
{
	t_maps	*map;

	map = (t_maps *)param;
	if (map->status == WON)
		print_on_screen(map, "YOU WON! AWESOME WORK", map->height + 1);
	if (map->status == LOST)
		print_on_screen(map, "YOU LOST! TRY AGIAN......", map->height);
	print_on_screen(map, "\"ESC to exit\"", map->height - 1);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->mlx);
}

void	print_moves(t_maps *map)
{
	char	*c;

	c = ft_itoa(map->moves);
	map->moveprint = ft_strjoin("Moves : ", c);
	ft_printf("%s\n", map->moveprint);
	map->moveprint = NULL;
}

void	bonus_print_moves(t_maps *map)
{
	char	*c;

	c = NULL;
	mlx_delete_image(map->mlx, map->print_moves);
	c = ft_itoa(map->moves);
	map->moveprint = ft_strjoin("Moves : ", c);
	map->print_moves = mlx_put_string(map->mlx, map->moveprint, \
	((map->width / 2) - (ft_strlen(map->moveprint) / 6.5)) \
	* PIXEL, (map->height - 3) * PIXEL / 2);
	free(map->moveprint);
	map->moveprint = NULL;
}

