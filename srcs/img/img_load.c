/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:52:21 by sukwon            #+#    #+#             */
/*   Updated: 2024/05/08 00:37:48 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	load_img(const char *img_path, t_maps *map, t_img i)
{
	// Try to load the file : png -> texture
	map->texture = mlx_load_png(img_path);
	if (!(map->texture))
		errors("Fail to mlx_load_png.", map);
	// Convert texture to a displayable texture -> img 
	// printf("i : %d\n", i);
	map->img[i] = mlx_texture_to_image(map->mlx, map->texture);
	if (!(map->img[i]))
		errors("Fail to  mlx_texture_to_image.", map);
	mlx_delete_texture(map->texture);
}

void	generate_imgs(t_maps *map)
{
	// Start mlx : make a window
	map->mlx = mlx_init((map->width + 1) * PIXEL, (map->height + 1) * PIXEL,\
	 "so_long", false);
	if (!map->mlx)
		errors("Fail to initiate window : mlx_init error.", map);
	load_img("images/bg.png", map, BG);
	load_img("images/wall.png", map, WALL);
	load_img("images/ply_R.png", map, PLY_R);
	load_img("images/ply_L.png", map, PLY_L);
	load_img("images/ply_F.png", map, PLY_F);
	load_img("images/ply_B.png", map, PLY_B);
	load_img("images/ply_start.png", map, PLY_START);
	load_img("images/ply_fail.png", map, PLY_FAIL);
	load_img("images/collective.png", map, COLLECTIVE);
	load_img("images/enm_B.png", map, ENM_B);
	load_img("images/enm_F.png", map, ENM_F);
	load_img("images/enm_L.png", map, ENM_L);
	load_img("images/enm_R.png", map, ENM_R);
	load_img("images/exit_close.png", map, EXIT_CLOSE);
	load_img("images/exit_open.png", map, EXIT_OPEN);
	load_img("images/collision.png", map, COLLISION);
}
