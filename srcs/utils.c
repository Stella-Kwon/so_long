/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:57:13 by skwon2            #+#    #+#             */
/*   Updated: 2024/04/25 15:33:30 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	errors(char *mes)
{
	if (mes)
		ft_putendl_fd("Error.", 2);
	else
	{
		ft_putstr_fd ("Error : ", 2);
		ft_putendl_fd(mes, 2);
	}
	return (FAILURE);
}
