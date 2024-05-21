/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:52:21 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/21 14:48:44 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	load_img(const char *img_path, t_maps *map, t_img i)
{
	map->texture = mlx_load_png(img_path);
	if (!(map->texture))
		errors("Fail to mlx_load_png.", map);
	map->img[i] = mlx_texture_to_image(map->mlx, map->texture);
	if (!(map->img[i]))
		errors("Fail to  mlx_texture_to_image.", map);
	mlx_delete_texture(map->texture);
}

void	generate_imgs(t_maps *map)
{
	map->mlx = mlx_init((map->width + 1) * PIXEL, (map->height + 1) * PIXEL, \
	"so_long", true);
	if (!map->mlx)
		errors("Fail to initiate window : mlx_init error.", map);
	load_img("textures/bg.png", map, BG);
	load_img("textures/wall.png", map, WALL);
	load_img("textures/ply_R.png", map, PLY_R);
	load_img("textures/ply_L.png", map, PLY_L);
	load_img("textures/ply_F.png", map, PLY_F);
	load_img("textures/ply_B.png", map, PLY_B);
	load_img("textures/ply_start.png", map, PLY_START);
	load_img("textures/collective.png", map, COLLECTIVE);
	load_img("textures/exit_close.png", map, EXIT_CLOSE);
	load_img("textures/exit_open.png", map, EXIT_OPEN);
	load_img("textures/yummy.png", map, YUMMY);
	load_img("textures/collision.png", map, COLLISION);
}
