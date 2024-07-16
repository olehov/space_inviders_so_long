/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_white_background.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:24:00 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/16 15:54:50 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/ft_image.h"
#include "../../headers/ft_window.h"
#include "../minilibx-linux/mlx.h"

static t_image	*set_background(t_image *image, t_window *window,
	int size_line, int bpp)
{
	int		x;
	int		y;
	int		pixel_index;

	y = 0;
	x = 0;
	while (y < window->height)
	{
		while (x < window->width)
		{
			pixel_index = (y * size_line) + (x * (bpp / 8));
			image->img_data[pixel_index] = 0xFF;
			image->img_data[pixel_index + 1] = 0xFF;
			image->img_data[pixel_index + 2] = 0xFF;
			if (bpp == 32)
				image->img_data[pixel_index + 3] = 0xFF;
			x++;
		}
		y++;
		x = 0;
	}
	return (image);
}

t_image	*create_white_background(t_window *window)
{
	t_image	*image;
	int		bpp;
	int		size_line;
	int		endian;

	image = malloc(sizeof(t_image) * sizeof(void *));
	image->img_ptr = mlx_new_image(window->mlx_ptr, window->width,
			window->height);
	if (image->img_ptr == NULL)
	{
		free(image);
		return (NULL);
	}
	image->img_data = mlx_get_data_addr(image->img_ptr, &bpp,
			&size_line, &endian);
	return (set_background(image, window, size_line, bpp));
}