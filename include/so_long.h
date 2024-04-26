/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:48:00 by skwon2            #+#    #+#             */
/*   Updated: 2024/04/26 14:27:55 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h> // 나중에 필요없으면 지워

# define FAILURE -1
# define SUCCESS 1

typedef struct s_pos
{
	int32_t	i; // height
	int32_t	j; // width
}				t_pos;

typedef struct s_maps
{
	int32_t	width;
	int32_t	height;
	char	*map_oneline;
	char	**map;
	int		collectives;
	t_pos	player;
	t_pos	exit;
}				t_maps;

typedef struct s_count
{
	int	exit;
	int	player;
	int	i;
	int	j;
}				t_count;

#endif