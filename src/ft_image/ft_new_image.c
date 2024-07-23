/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:58:43 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/23 14:48:16 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "../../headers/ft_image.h"
#include "../../headers/so_long.h"
#include "../minilibx-linux/mlx.h"

t_image	*ft_new_image(void *mlx_ptr, char *path)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (img == NULL)
	{
		return (NULL);
	}
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, IMAGE_SIZE, IMAGE_SIZE);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->height = IMAGE_SIZE;
	img->width = IMAGE_SIZE;
	return (img);
}
