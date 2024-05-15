/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:48:00 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/15 15:27:41 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define PIXEL 32
# define FAILURE -1
# define SUCCESS 1


typedef enum s_direct
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}			t_direct;

typedef enum s_status
{
	WON,
	LOST,
	PLAYING
}			t_status;

typedef enum s_img
{
	BG,
	WALL,
	PLY_L,
	PLY_R,
	PLY_B,
	PLY_F,
	ENM_L,
	ENM_R,
	ENM_B,
	ENM_F,
	COLLECTIVE,
	EXIT_CLOSE,
	EXIT_OPEN,
	COLLISION,
	PLY_FAIL,
	PLY_START,
	YUMMY,
	NUM_IMG
}			t_img;

typedef struct s_pos
{
	int32_t	i; // height
	int32_t	j; // width
}				t_pos;

typedef struct s_random
{
	int32_t	*i;
	int32_t	*j;
}				t_random;

typedef struct s_maps
{
	int32_t			width;
	int32_t			height;
	char			*map_oneline;
	char			**map;
	char			**maptmp;
	t_pos			player;
	t_pos			*enemy;
	t_pos			next;
	t_pos			exit;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t 	*img[NUM_IMG];
	mlx_image_t		*print_moves;
	t_random		random;
	char			*moveprint;
	int				status;
	int				ply_nowimg;
	int				*enm_nowimg;
	int				*enm_direction;
	int				enemy_count;
	char			*line;
	int				moves;
	int				tmp;
	int				collectives;
	int				collect_count;
}				t_maps;

typedef struct s_count
{
	int		exit;
	int		player;
	int		collectives;
	int		enemies;
	int32_t	i;
	int32_t	j;
}				t_count;

void	check_file_extension(char *file, t_maps *map);
void	check_instance_count(t_maps *map, t_count *num);
void	check_else_char(char c, t_maps *map);
void	check_position(t_maps *map, t_count *num);
void	check_rectangular(t_maps *map);
int		flood_fill(t_maps *map, t_count *num, int32_t i, int32_t j);
void	check_wall(t_maps *map);
void	errors(char *mes, t_maps *map);
int		read_map(char *file, t_maps *map);
void	generate_imgs(t_maps *map);
void	free_every(t_maps *map);
char	*all_free(char **res);
void	img_to_window(t_maps *map, t_count *num);
void	img_onoff(t_maps *map, int i, bool d);
void	disable_ply(t_maps *map);
void	player_keyhook(mlx_key_data_t keydata, void* param);
void	grab_collectives(t_maps *map, int i);
void	disable_exit(t_maps *map);
void	print_on_screen(t_maps *map, char *line, int32_t height);
void	ending_prints(mlx_key_data_t keydata,void* param);
void	print_moves(t_maps *map);
void	the_next(t_maps *map, t_pos next, t_direct i);
void	move_enemy(void *param);
void	disable_enemy(t_maps *map);
void	the_next(t_maps *map, t_pos next, t_direct i);
void	bonus_print_moves(t_maps *map);
void	bonus_disable_ply(t_maps *map);
void	initial_enemy(t_maps *map, t_random *random, int count);
#endif