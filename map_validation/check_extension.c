/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:56:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/05/14 15:16:40 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_file_extension(char *file, t_maps *map)
{
	int	pos;

	pos = ft_strlen(file) - 1;
	if (ft_strncmp(file + pos - 3, ".ber", 4) < 0)
		errors("invalid file extension", map);
}
