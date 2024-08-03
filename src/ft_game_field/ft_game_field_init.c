/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_field_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:10:58 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 18:19:19 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_libft/headers/libft.h"
#include "../../headers/so_long.h"
#include "../../headers/ft_map_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static void	*ft_close_file(int fd)
{
	close(fd);
	return (NULL);
}

static t_game_field	*new_game_field(void)
{
	t_game_field	*game_field;

	game_field = ft_calloc(sizeof(t_game_field), 1);
	if (game_field == NULL)
		return (NULL);
	game_field->collectible = NULL;
	game_field->enemys = NULL;
	game_field->game_field = NULL;
	game_field->game_field_imgs = NULL;
	game_field->player = NULL;
	game_field->background = NULL;
	return (game_field);
}

static void	*init_gamefield(void *mlx_ptr, char *str, int height,
		t_game_field *game_field)
{
	if (game_field == NULL)
		return (free(str), NULL);
	game_field->game_field = ft_split(str, '\n');
	if (game_field->game_field == NULL)
		return (free(str), free(game_field), NULL);
	game_field->height = height;
	game_field->width = ft_strlen(game_field->game_field[0]);
	if (ft_check_valid_map(game_field) == -1)
		return (free(str), ft_free_game_field(mlx_ptr, game_field), NULL);
	game_field->background = ft_screen_background(mlx_ptr,
			(game_field->width - 2) * IMAGE_SIZE,
			(game_field->height - 2) * IMAGE_SIZE);
	if (game_field->background == NULL)
		return (free(str), ft_free_game_field(mlx_ptr, game_field), NULL);
	game_field->background->pos.x = START_POS_X + IMAGE_SIZE;
	game_field->background->pos.y = IMAGE_SIZE;
	return (game_field);
}

static t_game_field	*init_field(void *mlx_ptr, char *str, int height)
{
	t_game_field	*game_field;

	game_field = new_game_field();
	if (init_gamefield(mlx_ptr, str, height, game_field) == NULL)
		return (NULL);
	game_field->game_field_imgs = init_field_imgs(mlx_ptr, game_field);
	if (game_field->game_field_imgs == NULL)
		return (free(str), ft_free_game_field(mlx_ptr, game_field), NULL);
	game_field->exit_gate = ft_exit_gate_init(mlx_ptr, game_field);
	if (game_field->exit_gate == NULL)
		return (free(str), ft_free_game_field(mlx_ptr, game_field), NULL);
	game_field->player = ft_player_init(mlx_ptr, game_field);
	if (game_field->player == NULL)
		return (free(str), ft_free_game_field(mlx_ptr, game_field), NULL);
	game_field->enemys = ft_enemy_init(mlx_ptr, game_field);
	if (game_field->enemys == NULL)
		return (free(str), ft_free_game_field(mlx_ptr, game_field), NULL);
	return (free(str), game_field);
}

t_game_field	*ft_game_field_init(void *mlx_ptr, const char *map_path)
{
	char			*str;
	char			*tmp;
	int				fd;
	int				counter;

	counter = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (perror(RED "Error: " RESET "File not found"), NULL);
	tmp = get_next_line(fd);
	if (tmp == NULL || tmp[0] != '1')
		return (perror(RED "Error: " RESET "Map not found"),
			ft_close_file(fd));
	str = ft_calloc(1, 1);
	if (str == NULL)
		return (free(tmp), ft_close_file(fd));
	while (tmp != NULL)
	{
		str = ft_join_and_free(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		counter++;
	}
	close(fd);
	return (init_field(mlx_ptr, str, counter));
}
