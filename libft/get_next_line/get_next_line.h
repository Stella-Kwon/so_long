/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:04:18 by suminkwon         #+#    #+#             */
/*   Updated: 2024/05/07 12:46:31 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../libft.h"
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *previous_read, char const *buffer);
void	*free_one(char **buffer);
#endif