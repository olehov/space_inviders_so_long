/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_field.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:10:58 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/16 16:16:06 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/ft_game_field.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static void	*ft_close_file(int fd)
{
	close(fd);
	return (NULL);
}

static t_game_field	*init_field(char *str, int counter)
{
	t_game_field	*game_field;

	game_field = malloc(sizeof(t_game_field));
	if (game_field == NULL)
	{
		free(str);
		return (NULL);
	}
	printf("Game field allocated\n");
	game_field->game_field = ft_split(str, '\n');
	if (game_field->game_field == NULL)
	{
		free(str);
		free(game_field);
		return (NULL);
	}
	game_field->height = counter;
	game_field->width = ft_strlen(game_field->game_field[0]);
	printf("Game field height:%i\n", game_field->height);
	printf("Game field width:%i\n", game_field->width);
	if (ft_check_valid_map(game_field) == -1)
	{
		free(str);
		ft_free_game_field(game_field);
		// free(game_field);
		return (NULL);
	}
	free(str);
	return (game_field);
}

t_game_field	*ft_init_game_field(const char *map_path)
{
	char			*str;
	char			*tmp;
	int				fd;
	int				counter;

	counter = 0;
	fd = open(map_path, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (ft_close_file(fd));
	str = ft_calloc(1, 1);
	if (str == NULL)
	{
		free(tmp);
		return (ft_close_file(fd));
	}
	while (tmp != NULL)
	{
		str = ft_join_and_free(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		counter++;
	}
	close(fd);
	return (init_field(str, counter));
}
