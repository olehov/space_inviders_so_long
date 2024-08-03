/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_field_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:38:37 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 15:14:56 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

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
