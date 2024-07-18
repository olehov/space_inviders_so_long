/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_field.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:10:58 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/18 16:04:16 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/ft_game_field.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/so_long.h"
#include "../../headers/ft_color_utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static void	*ft_close_file(int fd)
{
	close(fd);
	return (NULL);
}

// static int	*init_borders(void)
// {
// 	int	*borders;


// 	borders[0] = open("../../textures/xpm/background.xpm", O_RDONLY);
// 	borders[1] = open("../../textures/xpm/bottom_horizontal_line.xpm",
// 			O_RDONLY);
// 	borders[2] = open("../../textures/xpm/bottom_left_corner.xpm", O_RDONLY);
// 	borders[3] = open("../../textures/xpm/bottom_right_corner.xpm", O_RDONLY);
// 	borders[4] = open("../../textures/xpm/left_vertical_line.xpm", O_RDONLY);
// 	borders[5] = open("../../textures/xpm/right_vertical_line.xpm", O_RDONLY);
// 	borders[6] = open("../../textures/xpm/top_horizontal_line.xpm", O_RDONLY);
// 	borders[7] = open("../../textures/xpm/top_left_corner.xpm", O_RDONLY);
// 	borders[8] = open("../../textures/xpm/top_right_corner.xpm", O_RDONLY);
// }

static t_image	**init_field_imgs(void *mlx_ptr, int width, int height)
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
	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			field_imgs[i][j].height = 32;
			field_imgs[i][j].width = 32;
			printf("i=%i j=%i\n", i, j);
			if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						BACKGROUND_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else if (i == 0 && j == 0)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						TOP_L_CORNER_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else if (i == height - 1 && j == width - 1)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						BOTTOM_R_CORNER_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else if (i == height - 1 && j == 0)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						BOTTOM_L_CORNER_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else if (i == 0 && j == width - 1)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						TOP_R_CORNER_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else if (j == 0 && i > 0 && i < height - 1)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						LEFT_V_LINE_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else if (j == width - 1 && i > 0 && i < height - 1)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						RIGHT_V_LINE_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else if (i == 0 && j > 0 && j < width - 1)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						TOP_H_LINE_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else if (i == height - 1 && j > 0 && j < width - 1)
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						BOTTOM_H_LINE_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			else
			{
				field_imgs[i][j].img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						BACKGROUND_PATH, &field_imgs[i][j].width,
						&field_imgs[i][j].height);
			}
			if (field_imgs[i][j].img_ptr == NULL)
			{
				ft_printf(RED "Error" RESET "loading image at i=%i, j=%i\n",
					i, j);
				// Optional: Handle error (e.g., free allocated memory)
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (field_imgs);
}

static t_game_field	*init_field(void *mlx_ptr, char *str, int counter)
{
	t_game_field	*game_field;

	game_field = malloc(sizeof(t_game_field));
	if (game_field == NULL)
		return (free(str), NULL);
	printf("Game field allocated\n");
	game_field->game_field = ft_split(str, '\n');
	if (game_field->game_field == NULL)
		return (free(str), free(game_field), NULL);
	game_field->height = counter;
	game_field->width = ft_strlen(game_field->game_field[0]);
	printf("Game field height:%i\n", game_field->height);
	printf("Game field width:%i\n", game_field->width);
	if (ft_check_valid_map(game_field) == -1)
	{
		ft_free_game_field(mlx_ptr, game_field);
		return (free(str), NULL);
	}
	game_field->game_field_imgs = init_field_imgs(mlx_ptr, game_field->width,
			game_field->height);
	if (game_field->game_field_imgs == NULL)
	{
		ft_free_game_field(mlx_ptr, game_field);
		return (free(str), NULL);
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
