/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_field.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:10:58 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/26 16:03:47 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "../../headers/ft_game_field.h"
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

static t_image	**allocate_field_img(int width, int height)
{
	t_image	**field_imgs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	field_imgs = (t_image **)malloc(sizeof(t_image *) * height);
	if (field_imgs == NULL)
		return (NULL);
	while (i < height)
	{
		field_imgs[i] = (t_image *)malloc(sizeof(t_image) * width);
		if (field_imgs[i] == NULL)
		{
			while (j < i)
			{
				free(field_imgs[j]);
				j++;
			}
			free(field_imgs);
			return (NULL);
		}
		i++;
	}
	return (field_imgs);
}

static t_image	*init_player(void *mlx_ptr, t_game_field *game_field,
	int i, int j)
{
	if (game_field->game_field[i][j] == _player_start_pos)
	{
		return (ft_new_image(mlx_ptr, PLAYER_SPACESHIP));
	}
	return (NULL);
}

static t_image	*init_borders(void *mlx_ptr, t_game_field *game_field,
	int i, int j)
{
	if (i > 0 && i < game_field->height - 1 && j > 0
		&& j < game_field->width - 1)
		return (ft_new_image(mlx_ptr, BACKGROUND));
	else if (i == 0 && j == 0)
		return (ft_new_image(mlx_ptr, TOP_L_CORNER));
	else if (i == game_field->height - 1 && j == game_field->width - 1)
		return (ft_new_image(mlx_ptr, BOTTOM_R_CORNER));
	else if (i == game_field->height - 1 && j == 0)
		return (ft_new_image(mlx_ptr, BOTTOM_L_CORNER));
	else if (i == 0 && j == game_field->width - 1)
		return (ft_new_image(mlx_ptr, TOP_R_CORNER));
	else if (j == 0 && i > 0 && i < game_field->height - 1)
		return (ft_new_image(mlx_ptr, LEFT_V_LINE));
	else if (j == game_field->width - 1 && i > 0 && i < game_field->height - 1)
		return (ft_new_image(mlx_ptr, RIGHT_V_LINE));
	else if (i == 0 && j > 0 && j < game_field->width - 1)
		return (ft_new_image(mlx_ptr, TOP_H_LINE));
	else if (i == game_field->height - 1 && j > 0 && j < game_field->width - 1)
		return (ft_new_image(mlx_ptr, BOTTOM_H_LINE));
	return (NULL);
}

t_image	**init_field_imgs(void *mlx_ptr, t_game_field *game_field)
{
	t_image	**field_imgs;
	t_image	*new_img;
	int		i;
	int		j;

	i = -1;
	j = -1;
	field_imgs = allocate_field_img(game_field->width, game_field->height);
	if (field_imgs == NULL)
		return (NULL);
	while (++i < game_field->height)
	{
		while (++j < game_field->width)
		{
			ft_set_position(&field_imgs[i][j].pos, j * IMAGE_SIZE + START_POS_X,
				i * IMAGE_SIZE);
			new_img = init_borders(mlx_ptr, game_field, i, j);
			if (new_img == NULL)
				return (free_imgs(mlx_ptr, game_field), NULL);
			field_imgs[i][j].img_ptr = new_img->img_ptr;
			free(new_img);
		}
		j = -1;
	}
	return (field_imgs);
}

static t_game_field	*init_field(void *mlx_ptr, char *str, int counter)
{
	t_game_field	*game_field;

	game_field = malloc(sizeof(t_game_field));
	if (game_field == NULL)
		return (free(str), NULL);
	game_field->game_field = ft_split(str, '\n');
	if (game_field->game_field == NULL)
		return (free(str), free(game_field), NULL);
	game_field->height = counter;
	game_field->width = ft_strlen(game_field->game_field[0]);
	if (ft_check_valid_map(game_field) == -1)
		return (ft_free_game_field(mlx_ptr, game_field), free(str), NULL);
	game_field->game_field_imgs = init_field_imgs(mlx_ptr, game_field);
	if (game_field->game_field_imgs == NULL)
		return (ft_free_game_field(mlx_ptr, game_field), NULL);
	game_field->exit_gate = ft_exit_gate_init(mlx_ptr, game_field);
	if (game_field->exit_gate == NULL)
		return (ft_free_game_field(mlx_ptr, game_field), NULL);
	game_field->player = ft_player_init(mlx_ptr, game_field);
	if (game_field->player == NULL)
	{
		return (ft_free_game_field(mlx_ptr, game_field), NULL);
	}
	free(str);
	return (game_field);
}

t_game_field	*ft_init_game_field(void *mlx_ptr, const char *map_path)
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
	return (init_field(mlx_ptr, str, counter));
}
