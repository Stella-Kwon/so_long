/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:56:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/07 21:13:06 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_file_extension(char *file, t_maps *map)
{
	int	pos;

	pos = ft_strlen(file) - 1;
	// printf("pos : %s\n", file + pos - 3);
	if (ft_strncmp(file + pos - 3, ".ber", 4) < 0)
		errors("invalid file extension", map);
}
