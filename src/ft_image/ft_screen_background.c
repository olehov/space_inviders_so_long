/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:55:59 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 17:32:23 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static void	change_img_data(t_image *img, int size_line, int bpp)
{
	int		x;
	int		y;
	int		pixel;

	y = 0;
	x = 0;
	while (y < img->height)
	{
		while (x < img->width)
		{
			pixel = (y * size_line) + (x * (bpp / 8));
			img->img_data[pixel + 0] = 0;
			img->img_data[pixel + 1] = 0;
			img->img_data[pixel + 2] = 0;
			img->img_data[pixel + 3] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}

t_image	*ft_screen_background(void *mlx_ptr, int width, int height)
{
	t_image	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	img = ft_calloc(sizeof(t_image), 1);
	if (img == NULL)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (!img->img_ptr)
		return (free (img), NULL);
	img->height = height;
	img->width = width;
	img->img_data = mlx_get_data_addr(img->img_ptr, &bits_per_pixel,
			&size_line, &endian);
	change_img_data(img, size_line, bits_per_pixel);
	return (img);
}
