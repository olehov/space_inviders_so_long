/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:51:27 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 15:32:46 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/ft_color_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static int	check_open_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		return (perror(RED "Error: " RESET "File not found"), -1);
	}
	close(fd);
	return (1);
}

int	ft_check_valid_path(char *map_path)
{
	size_t	len;
	size_t	i;
	char	*file_extension;

	file_extension = ".ber";
	i = 3;
	len = ft_strlen(map_path) - 1;
	errno = ECANCELED;
	if (len < i)
		return (perror(RED "Error: " RESET ERROR_INVALID_FILE_EXTENSION), -1);
	while (i >= 0)
	{
		if (map_path[len] != file_extension[i])
			return (perror(RED "Error: " RESET ERROR_INVALID_FILE_EXTENSION),
				-1);
		if (i == 0)
			break ;
		i--;
		len--;
	}
	errno = ENOENT;
	if (check_open_file(map_path) == -1)
		return (-1);
	return (1);
}
