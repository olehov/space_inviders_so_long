/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:55:59 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/26 14:10:51 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/so_long.h"

t_image	*ft_screen_background(void *mlx_ptr, int width, int height)
{
	t_image	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int 	pixel;
	int		x;
	int		y;

	img = malloc(sizeof(t_image));
	if (img == NULL)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (!img->img_ptr)
		return (free (img), NULL);
	img->img_data = mlx_get_data_addr(img->img_ptr, &bits_per_pixel, &size_line, &endian);
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			pixel = (y * size_line) + (x * (bits_per_pixel / 8));
			img->img_data[pixel + 0] = 10; // Blue
			img->img_data[pixel + 1] = 10; // Green
			img->img_data[pixel + 2] = 0; // Red
			img->img_data[pixel + 3] = 0; // Alpha (if bits_per_pixel is 32)
		}
	}
	return (img);
}
